#ifndef CPPKATA_PRINTER_HXX
#define CPPKATA_PRINTER_HXX

#include <iostream>

#include "values.hxx"


template <Values value_T>
struct printer
{
	explicit printer()
	{
		std::cout << ToString<value_T>::name << std::endl;
	}
};

template <Values value_T>
struct printer_with_arguments
{
	explicit printer_with_arguments(int value)
	{
		std::cout << ToString<value_T>::name << ' ' << value << std::endl;
	}
};

#endif  // CPPKATA_PRINTER_HXX
