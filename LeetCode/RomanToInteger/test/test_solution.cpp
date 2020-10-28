#include <string>
using std::string;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(RomanToInteger_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample1)
{
	const string input = "III";
	const int expected = 3;
	Solution uut;

	int actual = uut.romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample2)
{
	const string input = "IV";
	const int expected = 4;
	Solution uut;

	int actual = uut.romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample3)
{
	const string input = "IX";
	const int expected = 9;
	Solution uut;

	int actual = uut.romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample4)
{
	const string input = "LVIII";
	const int expected = 58;
	Solution uut;

	int actual = uut.romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample5)
{
	const string input = "MCMXCIV";
	const int expected = 1994;
	Solution uut;

	int actual = uut.romanToInt(input);

	ASSERT_EQ(expected, actual);
}