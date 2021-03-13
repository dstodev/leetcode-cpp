#include "test_socket.hxx"
#include <windows/exceptions.hxx>

TEST_F(RunawayWindowsSock, constructor)
{
	(void) uut;
}

TEST_F(RunawayWindowsSock, set_blocking_no_connection)
{
	ASSERT_THROW(uut.set_blocking(false), WsaENotSock);
}
