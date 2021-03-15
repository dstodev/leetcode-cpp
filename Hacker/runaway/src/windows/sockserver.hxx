#ifndef CPPKATA_SOCKSERVER_HXX
#define CPPKATA_SOCKSERVER_HXX

#include "exceptions.hxx"
#include "isockserver.hxx"
#include "socket.hxx"

#include <winsock2.h>
#include <ws2tcpip.h>

#include <string>
#include <vector>

using windows_callback = ::accept_callback<Socket, sockaddr_in6>;


class SockServer : public ISockServer<Socket, sockaddr_in6>
{
public:
	SockServer();
	~SockServer() override;

	void bind(const char * port) override;
	void listen(size_t max_queue) override;
	std::future<bool> accept(const windows_callback & callback) override;

	[[nodiscard]] std::string receive(const Socket & client) const override;
	void send(const Socket & client, std::string message) const override;

private:
	Socket _sock;
	struct addrinfo _hints;

	/** @brief Wrapper function for calling accept() asynchronously.
	 * @param[in] sock     Socket (fd) to accept on.
	 * @param[in] callback Callback to invoke for accepted client.
	 * @return @c true if @a callback was invoked, @c false otherwise.
	 */
	static bool accept_thread(const Socket& sock, const windows_callback & callback);
};

#endif  // CPPKATA_SOCKSERVER_HXX
