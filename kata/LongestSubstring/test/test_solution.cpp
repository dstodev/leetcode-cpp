#include <string>
using std::string;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(LongestSubstring_Solution, defaultConstructor)
{
	Solution uut;
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstringGivenInputExample1)
{
	string input{"abcabcbb"};
	int expected = 3;  // "abc"

	Solution uut;

	int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstringGivenInputExample2)
{
	string input{"bbbbb"};
	int expected = 1;  // "b"

	Solution uut;

	int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstringGivenInputExample3)
{
	string input{"pwwkew"};
	int expected = 3;  // "wke"

	Solution uut;

	int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}

TEST(LongestSubstring_Solution, lengthOfLongestSubstringGivenInputExample4)
{
	string input;
	int expected = 0;  // ""

	Solution uut;

	int actual = uut.lengthOfLongestSubstring(input);

	ASSERT_EQ(expected, actual);
}
