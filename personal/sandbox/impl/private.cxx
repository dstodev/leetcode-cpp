#include "private.hxx"

#include <iostream>
using std::cout;
using std::endl;


void Intermediate::funcOne() const
{
	cout << "Implementation" << endl;
}


const Intermediate & ImplPrivate::getIntermediate() const
{
	return _intermediate;
}
