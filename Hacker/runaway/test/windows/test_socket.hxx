#ifndef CPPKATA_TEST_SOCKET_HXX
#define CPPKATA_TEST_SOCKET_HXX

#include <gtest/gtest.h>
#include <windows/socket.hxx>
#include <windows/wsawrapper.hxx>


class RunawayWindowsSocket : public ::testing::Test
{
protected:
	Socket uut;
	WsaWrapper wsa;  // Constructing this will initialize WSA, and destructing it will clean up
};


#endif  // CPPKATA_TEST_SOCKET_HXX
