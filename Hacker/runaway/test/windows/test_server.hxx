#ifndef CPPKATA_TEST_SERVER_HXX
#define CPPKATA_TEST_SERVER_HXX

#include <gtest/gtest.h>
#include <windows/sockserver.hxx>


class RunawayWindowsServer : public ::testing::Test
{
protected:
	SockServer uut;
};


#endif  // CPPKATA_TEST_SERVER_HXX
