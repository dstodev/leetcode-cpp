#ifndef CPPKATA_CLIENT_HXX
#define CPPKATA_CLIENT_HXX

#include "exceptions.hxx"
#include "wsawrapper.hxx"
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "isockclient.hxx"


class Client : public ISockClient
{
public:
	Client();
	~Client() override;

	/* ~~~~~~~~~~~~~~~~~~~~~~
	     RX/TX functions
	~~~~~~~~~~~~~~~~~~~~~~ */

	/** @brief Receive data from server.
	 * @return Data received from server.
	 */
	std::string receive() const;

	/** @brief Send @p message to server.
	 * @param[in] message Message to send to server.
	 */
	void send(std::string message) const;

	/* ~~~~~~~~~~~~~~~~~~~~~~~
	     Client functions
	~~~~~~~~~~~~~~~~~~~~~~~ */

	/** @brief Connect to server at @p address:port.
	 * @param[in] address Address to connect to in either IPv4 or IPv6 string format.
	 * @param[in] port    Port to connect through.
	 */
	void connect(const char * address, const char * port);

private:
	const WsaWrapper & _wsa;

	SOCKET _sock;
	struct addrinfo _hints;
};


#endif  // CPPKATA_CLIENT_HXX
