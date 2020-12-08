#include "test_socket.hxx"
#include <chrono>
#include <exceptions.hxx>
#include <future>
#include <gtest/gtest.h>
#include <memory>
#include <socket.hxx>

using std::future;
using std::future_error;
using std::future_status;
using std::ref;
using std::unique_ptr;
using std::chrono::milliseconds;

void SimpleAcceptCallback(SOCKET client, unique_ptr<sockaddr_in6> addr, unique_ptr<int> addr_len)
{
	(void) client;
	(void) addr;
	(void) addr_len;
}

void BooleanAcceptCallback(SOCKET client, unique_ptr<sockaddr_in6> addr, unique_ptr<int> addr_len, bool & in)
{
	(void) client;
	(void) addr;
	(void) addr_len;

	closesocket(client);
	in = true;
}

TEST_F(RunawayWindowsSocket, constructor)
{
	(void) uut;
}

TEST_F(RunawayWindowsSocket, connect_no_server)
{
	// TODO: This test is slow. Speed it up!
	ASSERT_THROW(uut.connect("localhost", "12345"), WsaEConnRefused);
}

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
	accept_callback<> cb = SimpleAcceptCallback;

	uut.bind("12345");
	uut.listen(5);

	auto future = uut.accept(cb);
	auto status = future.wait_for(milliseconds(50));
	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
}

TEST_F(RunawayWindowsSocket, accept_listen_max_zero)
{
	accept_callback<> cb = SimpleAcceptCallback;

	uut.bind("12345");
	uut.listen(0);

	auto future = uut.accept(cb);
	auto status = future.wait_for(milliseconds(50));
	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
}

TEST_F(RunawayWindowsSocket, accept_no_listen)
{
	accept_callback<> cb = SimpleAcceptCallback;

	uut.bind("12345");

	auto future = uut.accept(cb);
	auto status = future.wait_for(milliseconds(50));
	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_THROW(future.get(), WsaEInval);
}

TEST_F(RunawayWindowsSocket, accept_with_client)
{
	Socket client;
	bool success = false;
	accept_callback<bool &> cb = BooleanAcceptCallback;

	uut.bind("12345");
	uut.listen(5);
	client.connect("localhost", "12345");

	auto future = uut.accept(cb, success);
	auto status = future.wait_for(milliseconds(50));
	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_TRUE(future.get());
	ASSERT_TRUE(success);
}

TEST_F(RunawayWindowsSocket, set_blocking_default_false)
{
	accept_callback<> cb = SimpleAcceptCallback;

	uut.bind("12345");
	uut.listen(5);

	auto future = uut.accept(cb);
	auto status = future.wait_for(milliseconds(50));
	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_FALSE(future.get());
}

TEST_F(RunawayWindowsSocket, set_blocking_true)
{
	Socket client;
	accept_callback<> cb = SimpleAcceptCallback;

	uut.bind("12345");
	uut.listen(5);

	uut.set_blocking(true);

	auto future = uut.accept(cb);
	auto status = future.wait_for(milliseconds(0));
	ASSERT_TRUE(future.valid());
	ASSERT_NE(future_status::ready, status);

	client.connect("localhost", "12345");
	status = future.wait_for(milliseconds(50));
	ASSERT_TRUE(future.valid());
	ASSERT_EQ(future_status::ready, status);
	ASSERT_TRUE(future.get());
}
