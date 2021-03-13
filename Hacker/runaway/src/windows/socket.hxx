#ifndef CPPKATA_SOCKET_HXX
#define CPPKATA_SOCKET_HXX

#include <isocket.hxx>

#include <winsock2.h>

#include "wsawrapper.hxx"


class Socket : public ISocket<SOCKET>
{
public:
	Socket();
	virtual ~Socket() override = default;

	Socket & operator=(const SOCKET & fd) override;
	operator SOCKET() const;

	void sock_fd(SOCKET fd) override;
	SOCKET sock_fd() const override;

	void set_blocking(bool mode) override;

private:
	const WsaWrapper & _wsa;
	SOCKET _sock;
};

#endif  // CPPKATA_SOCKET_HXX
