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

	int actual = Solution::romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample2)
{
	const string input = "IV";
	const int expected = 4;

	int actual = Solution::romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample3)
{
	const string input = "IX";
	const int expected = 9;

	int actual = Solution::romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample4)
{
	const string input = "LVIII";
	const int expected = 58;

	int actual = Solution::romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, romanToInt_GivenInputExample5)
{
	const string input = "MCMXCIV";
	const int expected = 1994;

	int actual = Solution::romanToInt(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_I)
{  // 1
	const string input = "I";
	const string expected = "I";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 1, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_II)
{  // 2
	const string input = "II";
	const string expected = "II";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 2, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_III)
{  // 3
	const string input = "III";
	const string expected = "III";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 3, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_IV)
{  // 4
	const string input = "IV";
	const string expected = "IV";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 2, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_V)
{  // 5
	const string input = "V";
	const string expected = "V";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 1, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_IX)
{  // 9
	const string input = "IX";
	const string expected = "IX";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 2, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_X)
{  // 10
	const string input = "X";
	const string expected = "X";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 1, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_XL)
{  // 40
	const string input = "XL";
	const string expected = "XL";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 2, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_L)
{  // 50
	const string input = "L";
	const string expected = "L";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 1, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_XC)
{  // 90
	const string input = "XC";
	const string expected = "XC";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 2, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_C)
{  // 100
	const string input = "C";
	const string expected = "C";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 1, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_CD)
{  // 400
	const string input = "CD";
	const string expected = "CD";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 2, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_D)
{  // 500
	const string input = "D";
	const string expected = "D";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 1, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_CM)
{  // 900
	const string input = "CM";
	const string expected = "CM";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 2, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_M)
{  // 1000
	const string input = "M";
	const string expected = "M";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 1, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_IIII)
{
	const string input = "IIII";
	const string expected = "III";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 3, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_IVI)
{
	const string input = "IVI";
	const string expected = "IV";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 2, it);
}

TEST(RomanToInteger_Solution, getNextRomanSubstring_VI)
{
	const string input = "VI";
	const string expected = "V";

	auto it = input.begin();
	const string actual = Solution::getNextToken(it, input.end());

	ASSERT_EQ(expected, actual);
	ASSERT_EQ(input.begin() + 1, it);
}

TEST(RomanToInteger_Solution, mapTokenToUint_I)
{
	const string input = "I";
	const int expected = 1;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_II)
{
	const string input = "II";
	const int expected = 2;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_III)
{
	const string input = "III";
	const int expected = 3;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_IV)
{
	const string input = "IV";
	const int expected = 4;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_V)
{
	const string input = "V";
	const int expected = 5;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_IX)
{
	const string input = "IX";
	const int expected = 9;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_X)
{
	const string input = "X";
	const int expected = 10;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_XL)
{
	const string input = "XL";
	const int expected = 40;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_L)
{
	const string input = "L";
	const int expected = 50;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_XC)
{
	const string input = "XC";
	const int expected = 90;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_C)
{
	const string input = "C";
	const int expected = 100;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_CD)
{
	const string input = "CD";
	const int expected = 400;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_D)
{
	const string input = "D";
	const int expected = 500;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_CM)
{
	const string input = "CM";
	const int expected = 900;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_M)
{
	const string input = "M";
	const int expected = 1000;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}

TEST(RomanToInteger_Solution, mapTokenToUint_bad)
{
	const string input = "IIII";
	const int expected = -1;

	auto it = input.begin();
	const int actual = Solution::mapTokenToUint(input);

	ASSERT_EQ(expected, actual);
}