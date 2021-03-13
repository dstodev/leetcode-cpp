#include "sockclient.hxx"


SockClient::SockClient()
    : _hints()
{
	ZeroMemory(&_hints, sizeof(_hints));
	_hints.ai_family = AF_UNSPEC;
	_hints.ai_socktype = SOCK_STREAM;
	_hints.ai_protocol = IPPROTO_TCP;
}

SockClient::~SockClient()
{
	// TODO: Graceful shutdown
	shutdown(_sock, SD_SEND);
	closesocket(_sock);
}

void SockClient::connect(const char * address, const char * port)
{
	int status;

	// Resolve address & port
	struct addrinfo * result;
	status = getaddrinfo(address, port, &_hints, &result);
	if (status != 0) {
		map_to_exception(status);
	}

	// Connect to each resolved address until successful
	auto sock_fd = INVALID_SOCKET;
	for (struct addrinfo * iter = result; iter != nullptr && sock_fd == INVALID_SOCKET; iter = iter->ai_next) {
		sock_fd = socket(iter->ai_family, iter->ai_socktype, iter->ai_protocol);

		if (sock_fd == INVALID_SOCKET) {
			status = WSAGetLastError();
		}
		else {
			if (::connect(sock_fd, iter->ai_addr, (int) iter->ai_addrlen) == SOCKET_ERROR) {
				status = WSAGetLastError();
				sock_fd = INVALID_SOCKET;
			}
		}
	}
	freeaddrinfo(result);

	if (sock_fd == INVALID_SOCKET) {
		map_to_exception(status);
	}

	_sock = sock_fd;
}

std::string SockClient::receive()
{
	return std::__cxx11::string();
}

void SockClient::send(std::string message)
{}
