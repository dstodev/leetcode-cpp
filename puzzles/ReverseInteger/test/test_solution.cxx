#include <gtest/gtest.h>
#include <solution.hxx>
#include <string>

using std::string;


TEST(ReverseInteger_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(ReverseInteger_Solution, reverse_givenInputExample1)
{
	const int input = 123;
	const int expected = 321;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_givenInputExample2)
{
	const int input = -123;
	const int expected = -321;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_givenInputExample3)
{
	const int input = 120;
	const int expected = 21;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_givenInputExample4)
{
	const int input = 0;
	const int expected = 0;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_zeroInMiddleOfNumber)
{
	const int input = 901;
	const int expected = 109;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverse_multiply10Overflow)
{
	const int input = 1000000009;
	const int expected = 0;

	Solution uut;

	const int actual = uut.reverse(input);

	ASSERT_EQ(expected, actual);
}
