#include "mocksockserver.hxx"


MockSockServer::~MockSockServer()
{}

std::string MockSockServer::receive(int client) const
{
	return std::__cxx11::string();
}

void MockSockServer::send(int client, std::string message) const
{}

void MockSockServer::bind(const char * port)
{}

void MockSockServer::listen(size_t max_queue)
{}

std::future<bool> MockSockServer::accept(const accept_callback<int, MockSockaddr> & callback)
{
	return std::future<bool>();
}
