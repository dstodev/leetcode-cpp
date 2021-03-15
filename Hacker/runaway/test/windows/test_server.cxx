#include "test_server.hxx"

#include <chrono>
#include <future>
#include <memory>

#include <exceptions.hxx>
#include <mockcallable.hxx>
#include <sockclient.hxx>

using std::future;
using std::future_error;
using std::future_status;
using std::ref;
using std::unique_ptr;
using std::chrono::milliseconds;

using WindowsCallable = ::MockCallable<sockaddr_in6>;


TEST_F(RunawayWindowsServer, bind)
{
	uut.bind("12345");
}

TEST_F(RunawayWindowsServer, bind_bad_port)
{
	ASSERT_THROW(uut.bind("bad"), WsaTypeNotFound);
}

TEST_F(RunawayWindowsServer, bind_null_port)
{
	ASSERT_THROW(uut.bind(nullptr), WsaHostNotFound);
}

TEST_F(RunawayWindowsServer, listen)
{
	uut.bind("12345");
	uut.listen(5);
}

TEST_F(RunawayWindowsServer, listen_no_bind)
{
	ASSERT_THROW(uut.listen(5), WsaENotSock);
}

TEST_F(RunawayWindowsServer, accept)
{
	WindowsCallable cb;

	uut.bind("12345");
	uut.listen(5);

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
	ASSERT_FALSE(cb.was_fired());
}

TEST_F(RunawayWindowsServer, accept_listen_max_zero)
{
	WindowsCallable cb;

	uut.bind("12345");
	uut.listen(0);

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
	ASSERT_FALSE(cb.was_fired());
}

TEST_F(RunawayWindowsServer, accept_no_listen)
{
	WindowsCallable cb;

	uut.bind("12345");

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_THROW(future.get(), WsaEInval);
	ASSERT_FALSE(cb.was_fired());
}

TEST_F(RunawayWindowsServer, accept_with_client)
{
	SockClient client;
	WindowsCallable cb;

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

TEST_F(RunawayWindowsServer, set_blocking_default_false)
{
	WindowsCallable cb;

	uut.bind("12345");
	uut.listen(5);

	auto future = uut.accept(ref(cb));
	auto status = future.wait_for(milliseconds(50));

	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
	ASSERT_FALSE(cb.was_fired());
}

// TODO: Refactor this test
//TEST_F(RunawayWindowsServer, set_blocking_true)
//{
//	SockClient client;
//	WindowsCallable cb;
//
//	uut.bind("12345");
//	uut.listen(5);
//
//	uut.blocking(true);
//
//	auto future = uut.accept(ref(cb));
//	auto status = future.wait_for(milliseconds(0));
//
//	ASSERT_TRUE(future.valid());
//	ASSERT_NE(future_status::ready, status);
//	ASSERT_FALSE(cb.was_fired());
//
//	client.connect("localhost", "12345");
//	status = future.wait_for(milliseconds(50));
//
//	ASSERT_TRUE(future.valid());
//	ASSERT_EQ(future_status::ready, status);
//	ASSERT_TRUE(future.get());
//	ASSERT_TRUE(cb.was_fired());
//}
