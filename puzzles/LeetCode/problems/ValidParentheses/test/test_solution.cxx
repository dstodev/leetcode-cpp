#include <gtest/gtest.h>
#include <solution.hxx>
#include <string>

using std::string;


TEST(ValidParentheses_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(ValidParentheses_Solution, isValid_givenInputExample1)
{
	const string input = "()";

	const bool actual = Solution::isValid(input);

	ASSERT_TRUE(actual);
}

TEST(ValidParentheses_Solution, isValid_givenInputExample2)
{
	const string input = "()[]{}";

	const bool actual = Solution::isValid(input);

	ASSERT_TRUE(actual);
}

TEST(ValidParentheses_Solution, isValid_givenInputExample3)
{
	const string input = "(]";

	const bool actual = Solution::isValid(input);

	ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_givenInputExample4)
{
	const string input = "([)]";

	const bool actual = Solution::isValid(input);

	ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_multipleSameParentheses)
{
	const string input = "(())[[]]{{}}";

	const bool actual = Solution::isValid(input);

	ASSERT_TRUE(actual);
}

TEST(ValidParentheses_Solution, isValid_complexInput)
{
	const string input = "([]((){})())";

	const bool actual = Solution::isValid(input);

	ASSERT_TRUE(actual);
}

TEST(ValidParentheses_Solution, isValid_noInput)
{
	const string input;

	const bool actual = Solution::isValid(input);

	ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_oneOpeningCharacter)
{
	const string input = "(";

	const bool actual = Solution::isValid(input);

	ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_oneClosingCharacter)
{
	const string input = ")";

	const bool actual = Solution::isValid(input);

	ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_notBrackets)
{
	const string input = "no-brackets-here";

	const bool actual = Solution::isValid(input);

	ASSERT_FALSE(actual);
}
