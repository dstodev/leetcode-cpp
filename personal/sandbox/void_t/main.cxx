#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;


// Primary template
template <typename, typename = void>
struct has_value : std::false_type
{};

// Specialization for types with a ::value member (member can be static but is not required)
// T::value is evaluated in an SFINAE context, so the primary template will be used if T::value
// is an invalid expression.
// Note: the member must be public or otherwise accessible!
template <typename T>
struct has_value<T, std::void_t<decltype(T::value)>> : std::true_type
{};


struct WithValue
{
	int value = 0;
};

struct WithStaticValue
{
	static constexpr int value = 0;
};

struct WithoutValue
{};


int main()
{
	cout << std::boolalpha;
	cout << has_value<WithValue>::value << endl;        // true
	cout << has_value<WithStaticValue>::value << endl;  // true
	cout << has_value<WithoutValue>::value << endl;     // false

	return 0;
}
