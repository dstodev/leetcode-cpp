#include "sockserver.hxx"
#include <memory>

using std::future;
using std::make_unique;
using std::move;
using std::ref;
using std::string;
using std::thread;
using std::unique_ptr;

SockServer::SockServer()
    : _hints()
{
	ZeroMemory(&_hints, sizeof(_hints));
	_hints.ai_family = AF_UNSPEC;
	_hints.ai_socktype = SOCK_STREAM;
	_hints.ai_protocol = IPPROTO_TCP;
}

SockServer::~SockServer()
{
	closesocket(_sock);
}

void SockServer::bind(const char * port)
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

	freeaddrinfo(result);
	_sock = sock;

	// Set non-blocking mode on the socket
	_sock.blocking(false);
}

void SockServer::listen(size_t max_queue)
{
	int status;

	status = ::listen(_sock, max_queue);
	if (status == SOCKET_ERROR) {
		status = WSAGetLastError();
		map_to_exception(status);
	}
}

future<bool> SockServer::accept(const windows_callback & callback)
{
	future<bool> future;
	future = async(accept_thread, _sock, callback);
	return future;
}

bool SockServer::accept_thread(const Socket & sock, const windows_callback & callback)
{
	int status;
	auto addr = make_unique<sockaddr_in6>();
	int addr_len = sizeof(*addr);
	bool fired = false;

	Socket client_sock;
	client_sock = ::accept(sock, (sockaddr *) addr.get(), &addr_len);
	if (client_sock == INVALID_SOCKET) {
		status = WSAGetLastError();

		// EWOULDBLOCK is not an error, so ignore it if returned.
		if (status != WSAEWOULDBLOCK) {
			map_to_exception(status);
		}
	}
	else {
		callback(client_sock, move(addr), addr_len);
		fired = true;
	}

	return fired;
}

string SockServer::receive(const Socket & client) const
{
	return string();
}

void SockServer::send(const Socket & client, string message) const
{}
