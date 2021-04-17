#ifndef CPPKATA_RUNAWAYWINDOWSSOCK_HXX
#define CPPKATA_RUNAWAYWINDOWSSOCK_HXX

#include <gtest/gtest.h>
#include <windows/socket.hxx>


class RunawayWindowsSock : public ::testing::Test
{
protected:
	Socket uut;
};


#endif  // CPPKATA_RUNAWAYWINDOWSSOCK_HXX
