#include "socket.hxx"

#include "exceptions.hxx"

Socket::Socket()
    : _sock(INVALID_SOCKET)
    , _result(nullptr)
    , _ptr(nullptr)
    , _hints()
{
	int status;

	if ((status = WSAStartup(MAKEWORD(2, 2), &_data)) != 0) {

	}
}
