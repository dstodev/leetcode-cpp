#include <iostream>


struct Parent
{
	virtual ~Parent() = default;
	virtual void funcOne()
	{
		std::cout << "Parent: One" << std::endl;
	}
};


struct Child : Parent
{
	void funcOne()
	{
		std::cout << "Child: One" << std::endl;
	}
	void funcTwo()
	{
		std::cout << "Child: Two" << std::endl;
	}
};


int main()
{
	Parent * test = new Child;

	test->funcOne();

	static_cast<Child *>(test)->funcTwo();

	delete test;

	return 0;
}
