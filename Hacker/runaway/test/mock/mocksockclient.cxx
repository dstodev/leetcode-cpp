#include "mocksockclient.hxx"


MockSockClient::~MockSockClient()
{}

std::string MockSockClient::receive()
{
	return nullptr;
}

void MockSockClient::send(std::string message)
{}
