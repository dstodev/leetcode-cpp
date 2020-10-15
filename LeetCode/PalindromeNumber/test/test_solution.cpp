#include <gtest/gtest.h>

#include <solution.hpp>


TEST(PalindromeNumber_Solution, defaultConstructor)
{
	Solution uut;
}

TEST(PalindromeNumber_Solution, isPalindrome_GivenInputExample1)
{
	const int input = 121;
	const bool expected = true;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}

TEST(PalindromeNumber_Solution, isPalindrome_GivenInputExample2)
{
	const int input = -121;
	const bool expected = false;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}

TEST(PalindromeNumber_Solution, isPalindrome_GivenInputExample3)
{
	const int input = 10;
	const bool expected = false;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}

TEST(PalindromeNumber_Solution, isPalindrome_GivenInputExample4)
{
	const int input = -101;
	const bool expected = false;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}

TEST(PalindromeNumber_Solution, isPalindrome_EvenDigitCount)
{
	const int input = 1221;
	const bool expected = true;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}
