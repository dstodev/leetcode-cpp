#include "test_client.hxx"

TEST_F(RunawayWindowsClient, constructor)
{
	(void) uut;
}

TEST_F(RunawayWindowsClient, connect_no_server)
{
	// TODO: This test is slow. Speed it up!
	ASSERT_THROW(uut.connect("localhost", "12345"), WsaEConnRefused);
}
