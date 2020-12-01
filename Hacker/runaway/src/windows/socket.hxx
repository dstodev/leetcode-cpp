#ifndef CPPKATA_SOCKET_HXX
#define CPPKATA_SOCKET_HXX

#include <functional>
#include <memory>
#include <thread>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "exceptions.hxx"

template <typename... Args>
using accept_callback =
    std::function<void(SOCKET client, std::unique_ptr<sockaddr_in6> addr, std::unique_ptr<int> addr_len, Args...)>;

class Socket
{
public:
	Socket();
	~Socket();

	// Client functions
	void connect(const char * address, const char * port);

	// Server functions
	void bind(const char * port);
	void listen(size_t max_queue);

	template <typename... Args>
	void accept(const accept_callback<Args...> & callback, Args &&... args);

private:
	SOCKET _sock;
	WSADATA _data;
	struct addrinfo _hints;
};


template <typename... Args>
void Socket::accept(const accept_callback<Args...> & callback, Args &&... args)
{
	int status;
	auto addr = std::make_unique<sockaddr_in6>();
	auto addr_len = std::make_unique<int>(sizeof(*addr));

	SOCKET client_sock = ::accept(_sock, (sockaddr *) addr.get(), addr_len.get());
	if (client_sock == INVALID_SOCKET) {
		status = WSAGetLastError();

		// EWOULDBLOCK is not an error, so ignore it if returned.
		if (status != WSAEWOULDBLOCK) {
			map_to_exception(status);
		}
	}
	else {
		std::thread(callback, client_sock, move(addr), move(addr_len), std::ref(args)...).detach();
	}
}

#endif  // CPPKATA_SOCKET_HXX
