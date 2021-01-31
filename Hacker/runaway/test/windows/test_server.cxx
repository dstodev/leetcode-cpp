#include "test_server.hxx"
#include <chrono>
#include <client.hxx>
#include <exceptions.hxx>
#include <future>
#include <gtest/gtest.h>
#include <memory>
#include <server.hxx>

using std::future;
using std::future_error;
using std::future_status;
using std::ref;
using std::unique_ptr;
using std::chrono::milliseconds;


class MockCallable
{
public:
	MockCallable()
	    : _fired(false)
	{}
	~MockCallable() = default;
	MockCallable(const MockCallable & copy) = delete;
	MockCallable & operator=(const MockCallable & copy) = delete;

	void operator()(SOCKET client, unique_ptr<sockaddr_in6> addr, size_t addr_len)
	{
		(void) client;
		(void) addr;
		(void) addr_len;

		_fired = true;
	}

	bool was_fired() const
	{
		return _fired;
	}

private:
	bool _fired;
};


TEST_F(RunawayWindowsSocket, bind)
{
	uut.bind("12345");
}

TEST_F(RunawayWindowsSocket, bind_bad_port)
{
	ASSERT_THROW(uut.bind("bad"), WsaTypeNotFound);
}

TEST_F(RunawayWindowsSocket, bind_null_port)
{
	ASSERT_THROW(uut.bind(nullptr), WsaHostNotFound);
}

TEST_F(RunawayWindowsSocket, listen)
{
	uut.bind("12345");
	uut.listen(5);
}

TEST_F(RunawayWindowsSocket, listen_no_bind)
{
	ASSERT_THROW(uut.listen(5), WsaENotSock);
}

TEST_F(RunawayWindowsSocket, accept)
{
	MockCallable cb;

	uut.bind("12345");
	uut.listen(5);

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
	ASSERT_FALSE(cb.was_fired());
}

TEST_F(RunawayWindowsSocket, accept_listen_max_zero)
{
	MockCallable cb;

	uut.bind("12345");
	uut.listen(0);

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
	ASSERT_FALSE(cb.was_fired());
}

TEST_F(RunawayWindowsSocket, accept_no_listen)
{
	MockCallable cb;

	uut.bind("12345");

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_THROW(future.get(), WsaEInval);
	ASSERT_FALSE(cb.was_fired());
}

TEST_F(RunawayWindowsSocket, accept_with_client)
{
	Client client;
	MockCallable cb;

	uut.bind("12345");
	uut.listen(5);
	client.connect("localhost", "12345");

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_TRUE(future.get());
	ASSERT_TRUE(cb.was_fired());
}

TEST_F(RunawayWindowsSocket, set_blocking_default_false)
{
	MockCallable cb;

	uut.bind("12345");
	uut.listen(5);

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
	ASSERT_FALSE(cb.was_fired());
}

TEST_F(RunawayWindowsSocket, set_blocking_true)
{
	Client client;
	MockCallable cb;

	uut.bind("12345");
	uut.listen(5);

	uut.set_blocking(true);

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(0));

	ASSERT_TRUE(future.valid());
	ASSERT_NE(future_status::ready, status);
	ASSERT_FALSE(cb.was_fired());

	client.connect("localhost", "12345");
	status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_TRUE(future.get());
	ASSERT_TRUE(cb.was_fired());
}
