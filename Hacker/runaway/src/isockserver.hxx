#ifndef CPPKATA_ISOCKSERVER_HXX
#define CPPKATA_ISOCKSERVER_HXX

#include <future>
#include <string>


template <typename sock_t>
class ISockServer
{
public:
	virtual ~ISockServer() = 0;

	/* ~~~~~~~~~~~~~~~~~~~~~~
	     RX/TX functions
	~~~~~~~~~~~~~~~~~~~~~~ */

	/** @brief Receive data from @p client.
	 * @param[in] client Client socket (fd) to receive data from.
	 * @return Data received from @p client socket (fd).
	 */
	virtual std::string receive(sock_t client) const = 0;

	/** @brief Send @p message to @p client.
	 * @param[in] client  Client socket (fd) to send @p message to.
	 * @param[in] message Message to send to @p client socket (fd).
	 */
	virtual void send(sock_t client, std::string message) const = 0;

	/* ~~~~~~~~~~~~~~~~~~~~~~~
	     Server functions
	~~~~~~~~~~~~~~~~~~~~~~~ */

	/** @brief Bind the socket to a port.
	 * @param[in] port The port to bind to.
	 */
	virtual void bind(const char * port) = 0;

	/** @brief Listen for clients.
	 * @param[in] max_queue Maximum queue size for connecting clients.
	 */
	virtual void listen(size_t max_queue) = 0;

	/** @brief Set the socket to blocking or non-blocking mode.
	 * @param[in] mode @c true for blocking mode,
	 *                 @c false for non-blocking mode.
	 */
	virtual void set_blocking(bool mode) = 0;
};


template <typename T>
inline ISockServer<T>::~ISockServer() = default;


#endif  // CPPKATA_ISOCKSERVER_HXX
