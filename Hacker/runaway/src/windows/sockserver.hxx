#ifndef CPPKATA_SOCKSERVER_HXX
#define CPPKATA_SOCKSERVER_HXX

#include "exceptions.hxx"
#include "isockserver.hxx"
#include "socket.hxx"

#include <winsock2.h>
#include <ws2tcpip.h>

#include <string>
#include <vector>

using windows_callback = ::accept_callback<SOCKET, sockaddr_in6>;


class SockServer : public ISockServer<SOCKET, sockaddr_in6>
{
public:
	SockServer();
	~SockServer() override;

	void bind(const char * port) override;
	void listen(size_t max_queue) override;
	std::future<bool> accept(const windows_callback & callback) override;

	std::string receive(SOCKET client) const override;
	void send(SOCKET client, std::string message) const override;

private:
	Socket _sock;
	struct addrinfo _hints;

	/** @brief Wrapper function for calling accept() asynchronously.
	 * @param[in] sock     SockServer (sock_fd) to accept on.
	 * @param[in] callback Callback to invoke for accepted client.
	 * @return @c true if @a callback was invoked, @c false otherwise.
	 */
	static bool accept_thread(SOCKET sock, const windows_callback & callback);
};

#endif  // CPPKATA_SOCKSERVER_HXX
