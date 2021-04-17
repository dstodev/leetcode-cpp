#include "mocksockserver.hxx"
#include <string>

using std::string;

MockSockServer::~MockSockServer() = default;

string MockSockServer::receive(const int & client) const
{
	return std::string();
}

void MockSockServer::send(const int & client, std::string message) const
{}

void MockSockServer::bind(const char * port)
{}

void MockSockServer::listen(size_t max_queue)
{}

std::future<bool> MockSockServer::accept(const accept_callback<int, MockSockaddr> & callback)
{
	return std::future<bool>();
}
