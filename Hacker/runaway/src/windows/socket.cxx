#include "socket.hxx"

#include "exceptions.hxx"


Socket::Socket()
    : _sock(INVALID_SOCKET)
    , _wsa(WsaWrapper::get_instance())
{}

Socket & Socket::operator=(const SOCKET & fd) {
	sock_fd(fd);
	return *this;
}

Socket::operator SOCKET() const
{
	return sock_fd();
}

void Socket::sock_fd(SOCKET fd)
{
	_sock = fd;
}

SOCKET Socket::sock_fd() const
{
	return _sock;
}

void Socket::set_blocking(bool mode)
{
	DWORD bytes;
	auto converted_mode = static_cast<unsigned long>(!mode);
	int status = WSAIoctl(_sock,
	                      FIONBIO,
	                      &converted_mode,
	                      sizeof(converted_mode),
	                      nullptr,
	                      0,
	                      &bytes,
	                      nullptr,
	                      nullptr);

	if (status == SOCKET_ERROR) {
		status = WSAGetLastError();
		map_to_exception(status);
	}
}
