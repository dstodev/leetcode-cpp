#include <string>
using std::string;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(ReverseInteger_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(ReverseInteger_Solution, reverse_GivenInputExample1)
{
	const int input = 123;
	const int expected = 321;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_GivenInputExample2)
{
	const int input = -123;
	const int expected = -321;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_GivenInputExample3)
{
	const int input = 120;
	const int expected = 21;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_GivenInputExample4)
{
	const int input = 0;
	const int expected = 0;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_ZeroInMiddleOfNumber)
{
	const int input = 901;
	const int expected = 109;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_Multiply10Overflow)
{
	const int input = 1000000009;
	const int expected = 0;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}
