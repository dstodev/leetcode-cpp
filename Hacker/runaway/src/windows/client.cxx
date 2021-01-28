#include "client.hxx"


Client::Client()
    : _sock(INVALID_SOCKET)
    , _hints()
    , _wsa(WsaWrapper::get_instance())
{
	ZeroMemory(&_hints, sizeof(_hints));
	_hints.ai_family = AF_UNSPEC;
	_hints.ai_socktype = SOCK_STREAM;
	_hints.ai_protocol = IPPROTO_TCP;
}

Client::~Client()
{
	// TODO: Graceful shutdown
	shutdown(_sock, SD_SEND);
	closesocket(_sock);
}

void Client::connect(const char * address, const char * port)
{
	int status;

	// Resolve address & port
	struct addrinfo * result;
	status = getaddrinfo(address, port, &_hints, &result);
	if (status != 0) {
		map_to_exception(status);
	}

	// Connect to each resolved address until successful
	auto sock = INVALID_SOCKET;
	for (struct addrinfo * iter = result; iter != nullptr && sock == INVALID_SOCKET; iter = iter->ai_next) {
		sock = socket(iter->ai_family, iter->ai_socktype, iter->ai_protocol);

		if (sock == INVALID_SOCKET) {
			status = WSAGetLastError();
			map_to_exception(status);
		}

		if (::connect(sock, iter->ai_addr, (int) iter->ai_addrlen) == SOCKET_ERROR) {
			status = WSAGetLastError();
			sock = INVALID_SOCKET;
		}
	}
	freeaddrinfo(result);

	if (sock == INVALID_SOCKET) {
		map_to_exception(status);
	}

	_sock = sock;
}
