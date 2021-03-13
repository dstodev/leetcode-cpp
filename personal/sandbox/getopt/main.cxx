#include <cstdio>
using std::printf;

#include <cmath>
using std::log10;

int main(int argc, const char * argv[])
{
	printf("%d arguments:\n", argc - 1);
	for (size_t i = 1; i < argc; ++i) {
		printf("  %*d. %s\n", static_cast<int>(log10(argc - 1)) + 1, i, argv[i]);
	}
}
