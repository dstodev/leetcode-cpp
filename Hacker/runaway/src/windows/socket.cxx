#include "socket.hxx"

#include "exceptions.hxx"


Socket::Socket()
    : _wsa(WsaWrapper::get_instance())
    , _sock(INVALID_SOCKET)
    , _blocking(true)  // Default state when connected is 'true'
{}

Socket::~Socket() = default;

Socket & Socket::operator=(const SOCKET & fd)
{
	this->fd(fd);
	return *this;
}

Socket::operator SOCKET() const
{
	return fd();
}

void Socket::fd(SOCKET fd)
{
	_sock = fd;
}

SOCKET Socket::fd() const
{
	return _sock;
}

void Socket::blocking(bool mode)
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

	_blocking = mode;
}

bool Socket::blocking() const
{
	return _blocking;
}
