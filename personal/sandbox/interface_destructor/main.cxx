#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::make_unique;
using std::unique_ptr;


struct InterfacePureVirtual
{
	virtual ~InterfacePureVirtual() = 0;
};
inline InterfacePureVirtual::~InterfacePureVirtual()  // = default;
{
	cout << "Interface Pure Virtual Destructor" << endl;
}

struct InterfaceDefaulted
{
	virtual ~InterfaceDefaulted()  // = default;
	{
		cout << "Interface Defaulted Destructor" << endl;
	}
};

struct DerivedPureVirtual : InterfacePureVirtual
{
	~DerivedPureVirtual() override
	{
		cout << "Derived Pure Virtual Destructor" << endl;
	}
};

struct DerivedDefaulted : InterfaceDefaulted
{
	~DerivedDefaulted() override
	{
		cout << "Derived Defaulted Destructor" << endl;
	}
};


int main()
{
	{
		cout << "Instantiating interface:" << endl;
		/* InterfacePureVirtual interface;  // Cannot compile! This is good. */
		InterfaceDefaulted interface;  // This is bad! Interfaces should not be instantiable.
	}
	{
		cout << endl;
		cout << "Instantiating a pure-virtual-destructed derived class:" << endl;
		unique_ptr<InterfacePureVirtual> derived_pure_virtual = make_unique<DerivedPureVirtual>();
	}
	{
		cout << endl;
		cout << "Instantiating a default-destructed derived class:" << endl;
		unique_ptr<InterfaceDefaulted> derived_defaulted = make_unique<DerivedDefaulted>();
	}

	return 0;
}
