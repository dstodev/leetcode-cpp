#include <iostream>

using std::cout;
using std::endl;

#include "for_enum.hxx"
#include "printer.hxx"
#include "values.hxx"


int main()
{
	int a = 5;

	for_enum<Values, 3, printer> {};
	for_enum<Values, 3, printer_with_arguments> {a};

	cout << a << endl;

	return 0;
}
