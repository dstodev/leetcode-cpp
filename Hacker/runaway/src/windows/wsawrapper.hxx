#ifndef CPPKATA_WSAWRAPPER_HXX
#define CPPKATA_WSAWRAPPER_HXX

#include <winsock2.h>
#include <ws2tcpip.h>


class WsaWrapper
{
public:
	static WsaWrapper & get_instance();

	WsaWrapper(const WsaWrapper & copy) = delete;
	WsaWrapper & operator=(const WsaWrapper & copy) = delete;

private:
	WSADATA _data;

	WsaWrapper();
	~WsaWrapper();
};


#endif  // CPPKATA_WSAWRAPPER_HXX
