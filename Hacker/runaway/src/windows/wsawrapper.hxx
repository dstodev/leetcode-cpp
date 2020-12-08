#ifndef CPPKATA_WSAWRAPPER_HXX
#define CPPKATA_WSAWRAPPER_HXX

#include <winsock2.h>
#include <ws2tcpip.h>


class WsaWrapper
{
public:
	WsaWrapper();
	~WsaWrapper();

private:
	WSADATA _data;
};


#endif  // CPPKATA_WSAWRAPPER_HXX
