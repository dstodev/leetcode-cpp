#include <iostream>


struct Parent
{
	virtual ~Parent() = default;
	virtual void func_one()
	{
		std::cout << "Parent: One" << std::endl;
	}
};

struct Child : Parent
{
	void func_one()
	{
		std::cout << "Child: One" << std::endl;
	}
	void func_two()
	{
		std::cout << "Child: Two" << std::endl;
	}
};


int main()
{
	Parent * test = new Child;

	test->func_one();

	static_cast<Child *>(test)->func_two();

	delete test;

	return 0;
}
