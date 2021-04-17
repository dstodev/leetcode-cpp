#include "private.hxx"

#include <iostream>
using std::cout;
using std::endl;


void Intermediate::func_one() const
{
	cout << "Implementation" << endl;
}


const Intermediate & ImplPrivate::getIntermediate() const
{
	return _intermediate;
}
