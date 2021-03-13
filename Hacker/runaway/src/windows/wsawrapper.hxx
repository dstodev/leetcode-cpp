#ifndef CPPKATA_WSAWRAPPER_HXX
#define CPPKATA_WSAWRAPPER_HXX

#include <winsock2.h>
#include <ws2tcpip.h>


/** Singleton wrapper around WSA. Construction of the object initializes WSA, and destruction cleans it up.
 */
class WsaWrapper
{
public:
	/** @brief Get a reference to the WsaWrapper singleton.
	 * @return WsaWrapper singleton reference.
	 */
	static WsaWrapper & get_instance();

	WsaWrapper(const WsaWrapper & copy) = delete;
	WsaWrapper & operator=(const WsaWrapper & copy) = delete;

private:
	WSADATA _data;

	WsaWrapper();
	~WsaWrapper();
};

#endif  // CPPKATA_WSAWRAPPER_HXX
