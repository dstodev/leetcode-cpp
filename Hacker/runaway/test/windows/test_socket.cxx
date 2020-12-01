#include <exceptions.hxx>
#include <gtest/gtest.h>
#include <memory>
#include <socket.hxx>

using std::unique_ptr;

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

TEST(RunawayWindowsSocket, constructor)
{
	Socket uut;
	(void) uut;
}

TEST(RunawayWindowsSocket, connect_no_server)
{
	// TODO: This test is slow. Speed it up!
	Socket uut;
	ASSERT_THROW(uut.connect("localhost", "12345"), WsaEConnRefused);
}

TEST(RunawayWindowsSocket, bind)
{
	Socket uut;
	uut.bind("12345");
}

TEST(RunawayWindowsSocket, bind_bad_port)
{
	Socket uut;
	ASSERT_THROW(uut.bind("bad"), WsaTypeNotFound);
}

TEST(RunawayWindowsSocket, listen)
{
	Socket uut;
	uut.bind("12345");
	uut.listen(5);
}

TEST(RunawayWindowsSocket, listen_no_bind)
{
	Socket uut;
	ASSERT_THROW(uut.listen(5), WsaENotSock);
}

TEST(RunawayWindowsSocket, accept)
{
	Socket uut;
	uut.bind("12345");
	uut.listen(5);

	accept_callback<> cb = SimpleAcceptCallback;
	uut.accept(cb);
}

TEST(RunawayWindowsSocket, accept_no_listen)
{
	Socket uut;
	uut.bind("12345");

	accept_callback<> cb = SimpleAcceptCallback;
	ASSERT_THROW(uut.accept(cb), WsaEInval);
}

TEST(RunawayWindowsSocket, accept_with_client)
{
	Socket uut;
	Socket client;
	bool success = false;

	uut.bind("12345");
	uut.listen(5);
	client.connect("localhost", "12345");

	accept_callback<bool &> cb = BooleanAcceptCallback;
	uut.accept(cb, success);

	// TODO: Find a more reliable way of testing the thread's behavior. This is terrible!
	for (int i; i < 1000000; ++i);

	ASSERT_TRUE(success);
}