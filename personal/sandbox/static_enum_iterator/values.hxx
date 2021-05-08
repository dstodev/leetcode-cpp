#ifndef CPPKATA_VALUES_H
#define CPPKATA_VALUES_H


enum class Values
{
	Zero,
	One,
	Two,
};


template <Values>
struct ToString
{};

template <>
struct ToString<Values::Zero>
{
	static constexpr const char * name = "Zero";
};

template <>
struct ToString<Values::One>
{
	static constexpr const char * name = "One";
};

template <>
struct ToString<Values::Two>
{
	static constexpr const char * name = "Two";
};

#endif  // CPPKATA_VALUES_H
