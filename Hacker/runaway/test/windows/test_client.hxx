#ifndef CPPKATA_RUNAWAYWINDOWSCLIENT_HXX
#define CPPKATA_RUNAWAYWINDOWSCLIENT_HXX

#include <gtest/gtest.h>
#include <windows/client.hxx>


class RunawayWindowsClient : public ::testing::Test
{
protected:
	Client uut;
};


#endif  // CPPKATA_RUNAWAYWINDOWSCLIENT_HXX
