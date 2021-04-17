#ifndef CPPKATA_MOCKSOCKCLIENT_HXX
#define CPPKATA_MOCKSOCKCLIENT_HXX

#include <isockclient.hxx>
#include <string>


class MockSockClient : public ISockClient
{
public:
	virtual ~MockSockClient() override;
	virtual std::string receive() override;
	virtual void send(std::string message) override;
};


#endif  // CPPKATA_MOCKSOCKCLIENT_HXX
