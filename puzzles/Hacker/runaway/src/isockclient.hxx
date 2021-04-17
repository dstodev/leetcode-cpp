#ifndef CPPKATA_ISOCKCLIENT_HXX
#define CPPKATA_ISOCKCLIENT_HXX

#include <string>

#include "isocket.hxx"


class ISockClient
{
public:
	virtual ~ISockClient() = 0;

	/* ~~~~~~~~~~~~~~~~~~~~~~~
	     Client functions
	~~~~~~~~~~~~~~~~~~~~~~~ */

	/** @brief Connect to server at @p address:port.
	 * @param[in] address Address to connect to in either IPv4 or IPv6 string format.
	 * @param[in] port    Port to connect through.
	 */
	virtual void connect(const char * address, const char * port) = 0;

	/* ~~~~~~~~~~~~~~~~~~~~~~
	     RX/TX functions
	~~~~~~~~~~~~~~~~~~~~~~ */

	/** @brief Receive data from server.
	 * @return Data received from server.
	 */
	virtual std::string receive() = 0;

	/** @brief Send @p message to server.
	 * @param[in] message Message to send to server.
	 */
	virtual void send(std::string message) = 0;
};

inline ISockClient::~ISockClient() = default;

#endif  // CPPKATA_ISOCKCLIENT_HXX
