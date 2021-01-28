#ifndef CPPKATA_TEST_SERVER_HXX
#define CPPKATA_TEST_SERVER_HXX

#include <gtest/gtest.h>
#include <windows/server.hxx>


class RunawayWindowsSocket : public ::testing::Test
{
protected:
	Server uut;
};


#endif  // CPPKATA_TEST_SERVER_HXX
