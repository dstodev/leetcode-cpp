#ifndef CPPKATA_MOCKCALLABLE_HXX
#define CPPKATA_MOCKCALLABLE_HXX

#include <cstdint>
#include <memory>


template <typename sock_t, typename sockaddr_t>
class MockCallable
{
public:
	MockCallable();
	~MockCallable() = default;
	MockCallable(const MockCallable & copy) = delete;
	MockCallable & operator=(const MockCallable & copy) = delete;

	void operator()(sock_t client, std::unique_ptr<sockaddr_t> addr, std::size_t addr_len);

	bool was_fired() const;

private:
	bool _fired;
};


template <typename sock_t, typename sockaddr_t>
MockCallable<sock_t, sockaddr_t>::MockCallable()
    : _fired(false)
{}

template <typename sock_t, typename sockaddr_t>
void MockCallable<sock_t, sockaddr_t>::operator()(sock_t client, std::unique_ptr<sockaddr_t> addr, size_t addr_len)
{
	(void) client;
	(void) addr;
	(void) addr_len;

	_fired = true;
}

template <typename sock_t, typename sockaddr_t>
bool MockCallable<sock_t, sockaddr_t>::was_fired() const
{
	return _fired;
}


#endif  // CPPKATA_MOCKCALLABLE_HXX
