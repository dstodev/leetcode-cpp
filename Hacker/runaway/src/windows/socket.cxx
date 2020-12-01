#include "socket.hxx"
#include <memory>

using std::move;
using std::ref;
using std::thread;
using std::unique_ptr;

Socket::Socket()
    : _sock(INVALID_SOCKET)
    , _data()
    , _hints()
{
	int status;

	// Initialize Winsock
	status = WSAStartup(MAKEWORD(2, 2), &_data);
	if (status != 0) {
		map_to_exception(status);
	}

	ZeroMemory(&_hints, sizeof(_hints));
	_hints.ai_family = AF_UNSPEC;
	_hints.ai_socktype = SOCK_STREAM;
	_hints.ai_protocol = IPPROTO_TCP;
}

Socket::~Socket()
{
	closesocket(_sock);
	WSACleanup();
}

void Socket::connect(const char * address, const char * port)
{
	int status;

	// Reset AI_PASSIVE
	_hints.ai_flags &= ~AI_PASSIVE;

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

void Socket::bind(const char * port)
{
	int status;

	// Set AI_PASSIVE
	_hints.ai_flags |= AI_PASSIVE;

	// Resolve port
	struct addrinfo * result;
	status = getaddrinfo(nullptr, port, &_hints, &result);
	if (status != 0) {
		map_to_exception(status);
	}

	// Create a socket to bind with
	SOCKET sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (sock == INVALID_SOCKET) {
		status = WSAGetLastError();
		map_to_exception(status);
	}

	// Bind to socket
	status = ::bind(sock, result->ai_addr, (int) result->ai_addrlen);
	if (status == SOCKET_ERROR) {
		status = WSAGetLastError();
		freeaddrinfo(result);
		map_to_exception(status);
	}

	// Set non-blocking mode on the socket
	int mode = 1;
	DWORD bytes;
	status = WSAIoctl(sock, FIONBIO, &mode, sizeof(mode), nullptr, 0, &bytes, nullptr, nullptr);
	if (status == SOCKET_ERROR) {
		status = WSAGetLastError();
		freeaddrinfo(result);
		map_to_exception(status);
	}

	freeaddrinfo(result);
	_sock = sock;
}

void Socket::listen(size_t max_queue)
{
	int status;

	status = ::listen(_sock, max_queue);
	if (status == SOCKET_ERROR) {
		status = WSAGetLastError();
		map_to_exception(status);
	}
}
