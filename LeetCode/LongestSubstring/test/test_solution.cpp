#include <string>
using std::string;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(LongestSubstring_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstring_givenInputExample1)
{
	const string input {"abcabcbb"};
	const int expected = 3;  // "abc"

	Solution uut;

	const int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstring_givenInputExample2)
{
	const string input {"bbbbb"};
	const int expected = 1;  // "b"

	Solution uut;

	const int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstring_givenInputExample3)
{
	const string input {"pwwkew"};
	const int expected = 3;  // "wke"

	Solution uut;

	const int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstring_givenInputExample4)
{
	const string input;
	const int expected = 0;  // ""

	Solution uut;

	const int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstring_endOfString)
{
	const string input {"1231234"};
	const int expected = 4;  // "1234"

	Solution uut;

	const int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstring_oneCharacter)
{
	const string input {"1"};
	const int expected = 1;  // "1"

	Solution uut;

	const int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstring_palindrome)
{
	const string input {"1221"};
	const int expected = 2;  // "12" or "21"

	Solution uut;

	const int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}
