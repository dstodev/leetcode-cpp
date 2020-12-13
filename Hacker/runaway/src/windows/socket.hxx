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
using accept_callback = std::function<
    void(SOCKET client, std::unique_ptr<sockaddr_in6> addr, std::unique_ptr<int> addr_len, Args... args)>;

class Socket
{
public:
	Socket();
	~Socket();

	/* ~~~~~~~~~~~~~~~~~~~~~~~
	     Client functions
	~~~~~~~~~~~~~~~~~~~~~~~ */

	/** @brief Connect to server at @p address:port.
	 *
	 * @param[in] address Address to connect to in either IPv4 or IPv6 string format.
	 * @param[in] port Port to connect through.
	 */
	void connect(const char * address, const char * port);

	/* ~~~~~~~~~~~~~~~~~~~~~~~
	     Server functions
	~~~~~~~~~~~~~~~~~~~~~~~ */

	/** @brief Bind the socket to a port.
	 *
	 * @param[in] port The port to bind to.
	 */
	void bind(const char * port);

	/** @brief Listen for clients.
	 *
	 * @param[in] max_queue Maximum queue size for connecting clients.
	 */
	void listen(size_t max_queue);

	/** @brief Set the socket to blocking or non-blocking mode.
	 *
	 * @param[in] mode @c true for blocking mode,
	 *                 @c false for non-blocking mode.
	 */
	void set_blocking(bool mode);

	/** @brief Spawn a thread to accept() the next queued client connecting to the socket when in server mode.
	 *
	 * @param[in] callback Callback invoked with the accepted client socket (fd) and @a args.
	 * @param[in] args Arguments passed to @a callback.
	 * @return @c future for the spawned thread.
	 */
	template <typename... Args>
	std::future<bool> accept(const accept_callback<Args...> & callback, Args &&... args);

private:
	SOCKET _sock;
	struct addrinfo _hints;

	/** @brief Wrapper function for calling accept().
	 *
	 * @tparam Args Parameter pack for arguments passed to @a callback.
	 * @param sock Socket (fd) to accept on.
	 * @param callback Callback to invoke for accepted client.
	 * @param args Arguments passed to @a callback.
	 * @return @c true if @a callback was invoked, @c false otherwise.
	 */
	template <typename... Args>
	static bool accept_thread(SOCKET sock, const accept_callback<Args...> & callback, Args &&... args);
};

template <typename... Args>
std::future<bool> Socket::accept(const accept_callback<Args...> & callback, Args &&... args)
{
	std::future<bool> future;

	future = std::async(accept_thread<Args...>, _sock, callback, std::ref(std::forward<Args>(args))...);

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
