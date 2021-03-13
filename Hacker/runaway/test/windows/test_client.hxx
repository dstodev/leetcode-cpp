#ifndef CPPKATA_RUNAWAYWINDOWSCLIENT_HXX
#define CPPKATA_RUNAWAYWINDOWSCLIENT_HXX

#include <gtest/gtest.h>
#include <windows/sockclient.hxx>


class RunawayWindowsClient : public ::testing::Test
{
protected:
	SockClient uut;
};


#endif  // CPPKATA_RUNAWAYWINDOWSCLIENT_HXX
