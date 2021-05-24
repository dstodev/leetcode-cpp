#include <iostream>

using std::cout;
using std::endl;


template <int a, int b>
struct Base
{
	// Default false
	static const bool value = false;
};

template <int b>
struct Base<1, b>
{
	// True only when first template parameter (a) is 1
	static const bool value = true;
};

template <int a, int b>
struct Derived : Base<a, b>
{};


int main()
{
	constexpr int x = 0;

	cout << std::boolalpha;
	cout << Derived<0, x>::value << endl;  // Will use default
	cout << Derived<1, x>::value << endl;  // Will use specialization
}
