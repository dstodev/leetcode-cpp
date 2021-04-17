#include <gtest/gtest.h>
#include <solution.hxx>


TEST(PalindromeNumber_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(PalindromeNumber_Solution, isPalindrome_givenInputExample1)
{
	const int input = 121;
	const bool expected = true;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}

TEST(PalindromeNumber_Solution, isPalindrome_givenInputExample2)
{
	const int input = -121;
	const bool expected = false;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}

TEST(PalindromeNumber_Solution, isPalindrome_givenInputExample3)
{
	const int input = 10;
	const bool expected = false;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}

TEST(PalindromeNumber_Solution, isPalindrome_givenInputExample4)
{
	const int input = -101;
	const bool expected = false;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}

TEST(PalindromeNumber_Solution, isPalindrome_evenDigitCount)
{
	const int input = 1221;
	const bool expected = true;

	Solution uut;

	const bool actual = uut.isPalindrome(input);

	ASSERT_EQ(expected, actual);
}
