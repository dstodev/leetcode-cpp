#include "wsawrapper.hxx"

#include "exceptions.hxx"
#include <winsock2.h>


WsaWrapper & WsaWrapper::get_instance()
{
	static WsaWrapper instance;
	return instance;
}

WsaWrapper::WsaWrapper()
    : _data()
{
	// Initialize Winsock
	int status = WSAStartup(MAKEWORD(2, 2), &_data);
	if (status != 0) {
		map_to_exception(status);
	}
}

WsaWrapper::~WsaWrapper()
{
	WSACleanup();
}
