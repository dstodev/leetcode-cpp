#ifndef CPPKATA_SOCKCLIENT_HXX
#define CPPKATA_SOCKCLIENT_HXX

#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>

#include "exceptions.hxx"
#include "isockclient.hxx"
#include "socket.hxx"


class SockClient : public ISockClient
{
public:
	SockClient();
	~SockClient() override;

	void connect(const char * address, const char * port) override;

	std::string receive() override;
	void send(std::string message) override;

private:
	Socket _sock;
	struct addrinfo _hints;
};

#endif  // CPPKATA_SOCKCLIENT_HXX
