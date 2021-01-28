#ifndef CPPKATA_SERVER_HXX
#define CPPKATA_SERVER_HXX

#include "exceptions.hxx"
#include "isockserver.hxx"
#include "wsawrapper.hxx"
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>

template <typename... Args>
using accept_callback = std::function<
    void(SOCKET client, std::unique_ptr<sockaddr_in6> addr, std::unique_ptr<int> addr_len, Args... args)>;


class Server : public ISockServer<SOCKET>
{
public:
	Server();
	~Server();

	std::string receive(SOCKET client) const override;
	void send(SOCKET client, std::string message) const override;

	void bind(const char * port) override;
	void listen(size_t max_queue) override;
	void set_blocking(bool mode) override;

	/** @brief Spawn a thread to accept() the next queued client connecting to the socket.
	 * @param[in] callback Callback invoked with the accepted client socket (fd) and @a args.
	 * @param[in] args     Arguments passed to @a callback.
	 * @return @c future for the spawned thread.
	 */
	template <typename... Args>
	std::future<bool> accept(const accept_callback<Args...> & callback, Args &&... args);

private:
	const WsaWrapper & _wsa;

	SOCKET _sock;
	struct addrinfo _hints;

	/** @brief Wrapper function for calling accept().
	 * @tparam    Args     Parameter pack for arguments passed to @a callback.
	 * @param[in] sock     Server (fd) to accept on.
	 * @param[in] callback Callback to invoke for accepted client.
	 * @param[in] args     Arguments passed to @a callback.
	 * @return @c true if @a callback was invoked, @c false otherwise.
	 */
	template <typename... Args>
	static bool accept_thread(SOCKET sock, const accept_callback<Args...> & callback, Args &&... args);
};


template <typename... Args>
std::future<bool> Server::accept(const accept_callback<Args...> & callback, Args &&... args)
{
	std::future<bool> future;
	future = std::async(accept_thread<Args...>, _sock, callback, std::ref(std::forward<Args>(args))...);
	return future;
}

template <typename... Args>
bool Server::accept_thread(SOCKET sock, const accept_callback<Args...> & callback, Args &&... args)
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


#endif  // CPPKATA_SERVER_HXX
