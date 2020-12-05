#ifndef CPPKATA_SOCKET_HXX
#define CPPKATA_SOCKET_HXX

#include <functional>
#include <future>
#include <memory>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "exceptions.hxx"

template <typename... Args>
using accept_callback =
    std::function<void(SOCKET client, std::unique_ptr<sockaddr_in6> addr, std::unique_ptr<int> addr_len, Args... args)>;

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
	void set_blocking(bool mode);

	template <typename... Args>
	std::future<bool> accept(const accept_callback<Args...> & callback, Args &&... args);

private:
	SOCKET _sock;
	WSADATA _data;
	struct addrinfo _hints;

	template <typename... Args>
	static bool accept_thread(SOCKET sock, const accept_callback<Args...> & callback, Args &&... args);
};

template <typename... Args>
std::future<bool> Socket::accept(const accept_callback<Args...> & callback, Args &&... args)
{
	std::future<bool> future;

	future = std::async(accept_thread<Args...>, _sock, callback, std::ref(args)...);

	return future;
}

template <typename... Args>
bool Socket::accept_thread(SOCKET sock, const accept_callback<Args...> & callback, Args &&... args)
{
	int status;
	auto addr = std::make_unique<sockaddr_in6>();
	auto addr_len = std::make_unique<int>(sizeof(*addr));
	bool fired = false;

	SOCKET client_sock = ::accept(sock, (sockaddr *) addr.get(), addr_len.get());
	if (client_sock == INVALID_SOCKET) {
		status = WSAGetLastError();

		// EWOULDBLOCK is not an error, so ignore it if returned.
		if (status != WSAEWOULDBLOCK) {
			map_to_exception(status);
		}
	}
	else {
		callback(client_sock, std::move(addr), std::move(addr_len), std::forward<Args>(args)...);
		fired = true;
	}

	return fired;
}

#endif  // CPPKATA_SOCKET_HXX
