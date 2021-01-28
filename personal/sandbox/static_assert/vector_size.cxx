#include <vector>
using std::vector;


int main()
{
	// TODO: Explore this more in a future C++ spec.  Constexpr vector is not currently supported (c++20, 1/17/2020).
	constexpr vector<int> a {0, 1, 2};
	constexpr vector<int> b {3, 4, 5, 6};

	static_assert(a.size() > b.size(), "'a' is bigger than 'b'");

	return 0;
}
