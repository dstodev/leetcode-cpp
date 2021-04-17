#ifndef CPPKATA_MOCKCALLABLE_HXX
#define CPPKATA_MOCKCALLABLE_HXX

#include <cstdint>
#include <memory>
#include <socket.hxx>


template <typename sockaddr_t>
class MockCallable
{
public:
	MockCallable();
	~MockCallable() = default;
	MockCallable(const MockCallable & copy) = delete;
	MockCallable & operator=(const MockCallable & copy) = delete;

	void operator()(Socket client, std::unique_ptr<sockaddr_t> addr, std::size_t addr_len);

	bool was_fired() const;

private:
	bool _fired;
};


template <typename sockaddr_t>
MockCallable<sockaddr_t>::MockCallable()
    : _fired(false)
{}

template <typename sockaddr_t>
void MockCallable<sockaddr_t>::operator()(Socket client, std::unique_ptr<sockaddr_t> addr, size_t addr_len)
{
	(void) client;
	(void) addr;
	(void) addr_len;

	_fired = true;
}

template <typename sockaddr_t>
bool MockCallable<sockaddr_t>::was_fired() const
{
	return _fired;
}


#endif  // CPPKATA_MOCKCALLABLE_HXX
