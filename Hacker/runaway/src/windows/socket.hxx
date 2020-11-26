#ifndef CPPKATA_SOCKET_HXX
#define CPPKATA_SOCKET_HXX

#include <winsock2.h>
#include <ws2tcpip.h>

class Socket
{
public:
	Socket();

private:
	SOCKET _sock;
	WSADATA _data;
	struct addrinfo * _result;
	struct addrinfo * _ptr;
	struct addrinfo _hints;
};


#endif  // CPPKATA_SOCKET_HXX
