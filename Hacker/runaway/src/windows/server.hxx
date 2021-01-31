#ifndef CPPKATA_SERVER_HXX
#define CPPKATA_SERVER_HXX

#include "exceptions.hxx"
#include "isockserver.hxx"
#include "wsawrapper.hxx"
#include <string>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>

using windows_callback = ::accept_callback<SOCKET, sockaddr_in6>;


class Server : public ISockServer<SOCKET, sockaddr_in6>
{
public:
	Server();
	~Server();

	std::string receive(SOCKET client) const override;
	void send(SOCKET client, std::string message) const override;

	void bind(const char * port) override;
	void listen(size_t max_queue) override;
	std::future<bool> accept(const windows_callback & callback) override;
	void set_blocking(bool mode) override;

private:
	const WsaWrapper & _wsa;

	SOCKET _sock;
	struct addrinfo _hints;

	/** @brief Wrapper function for calling accept() asynchronously.
	 * @param[in] sock     Server (fd) to accept on.
	 * @param[in] callback Callback to invoke for accepted client.
	 * @return @c true if @a callback was invoked, @c false otherwise.
	 */
	static bool accept_thread(SOCKET sock, const windows_callback & callback);
};


#endif  // CPPKATA_SERVER_HXX
