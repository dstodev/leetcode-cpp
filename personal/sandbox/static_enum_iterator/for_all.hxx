#ifndef CPPKATA_FOR_ALL_HXX
#define CPPKATA_FOR_ALL_HXX

#include <cstddef>

using std::size_t;


template <typename Enum_T, size_t Enum_N, size_t i, template <Enum_T> class Visitor_T>
struct for_all_iterator
{
	template <typename... Args_T>
	explicit for_all_iterator(Args_T &&... args)
	{
		Visitor_T<static_cast<Enum_T>(i)>(args...);
		for_all_iterator<Enum_T, Enum_N, i + 1, Visitor_T>(args...);
	}
};

template <typename Enum_T, size_t Enum_N, template <Enum_T> class Visitor_T>
struct for_all_iterator<Enum_T, Enum_N, Enum_N, Visitor_T>
{
	template <typename... Args_T>
	explicit for_all_iterator(Args_T...)
	{
		/* i == Enum_N; do nothing. Break recursion chain. */
	}
};

template <typename Enum_T, size_t Enum_N, template <Enum_T> class Visitor_T>
struct for_all
{
	template <typename... Args_T>
	explicit for_all(Args_T... args)
	{
		for_all_iterator<Enum_T, Enum_N, 0, Visitor_T>(args...);
	}
};

#endif  // CPPKATA_FOR_ALL_HXX
