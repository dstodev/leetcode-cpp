#include "test_socket.hxx"
#include <windows/exceptions.hxx>

TEST_F(RunawayWindowsSock, constructor)
{
	(void) uut;
}

TEST_F(RunawayWindowsSock, set_blocking_no_connection)
{
	ASSERT_THROW(uut.blocking(false), WsaENotSock);
	ASSERT_TRUE(uut.blocking());  // Default is true; should be unchanged
}

TEST_F(RunawayWindowsSock, set_blocking)
{
	// TODO: This
}
