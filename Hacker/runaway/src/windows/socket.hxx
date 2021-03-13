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
	operator SOCKET() const override;

	void fd(SOCKET fd) override;
	SOCKET fd() const override;

	void blocking(bool mode) override;
	bool blocking() const override;

private:
	const WsaWrapper & _wsa;
	SOCKET _sock;
	bool _blocking;

//	int ioctl(DWORD control_code, )
};

#endif  // CPPKATA_SOCKET_HXX
