#ifndef CPPKATA_MOCKSOCKSERVER_HXX
#define CPPKATA_MOCKSOCKSERVER_HXX

#include <cstdint>

#include <isockserver.hxx>


struct MockSockaddr
{
	unsigned int sa_family;  // Address family
	char sa_data[14];        // Address value
};


class MockSockServer : public ISockServer<int, MockSockaddr>
{
public:
	virtual ~MockSockServer() override;

	virtual std::string receive(int client) const override;
	virtual void send(int client, std::string message) const override;

	virtual void bind(const char * port) override;
	virtual void listen(size_t max_queue) override;
	virtual std::future<bool> accept(const accept_callback<int, MockSockaddr> & callback) override;
};


#endif  // CPPKATA_MOCKSOCKSERVER_HXX
