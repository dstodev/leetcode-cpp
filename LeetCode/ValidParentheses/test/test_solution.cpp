#include <string>
using std::string;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(ValidParentheses_Solution, defaultConstructor)
{
	Solution uut;
}

TEST(ValidParentheses_Solution, isValid_GivenInputExample1)
{
    const string input = "()";
    Solution uut;

	const bool actual = uut.isValid(input);

	ASSERT_TRUE(actual);
}

TEST(ValidParentheses_Solution, isValid_GivenInputExample2)
{
    const string input = "()[]{}";
    Solution uut;

    const bool actual = uut.isValid(input);

    ASSERT_TRUE(actual);
}

TEST(ValidParentheses_Solution, isValid_GivenInputExample3)
{
    const string input = "(]";
    Solution uut;

    const bool actual = uut.isValid(input);

    ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_GivenInputExample4)
{
    const string input = "([)]";
    Solution uut;

    const bool actual = uut.isValid(input);

    ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_MultipleSameParentheses)
{
	const string input = "(())[[]]{{}}";
	Solution uut;

	const bool actual = uut.isValid(input);

	ASSERT_TRUE(actual);
}

TEST(ValidParentheses_Solution, isValid_ComplexInput)
{
    const string input = "([]((){})())";
    Solution uut;

    const bool actual = uut.isValid(input);

    ASSERT_TRUE(actual);
}

TEST(ValidParentheses_Solution, isValid_NoInput)
{
    const string input = "";
    Solution uut;

    const bool actual = uut.isValid(input);

    ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_OneOpeningCharacter)
{
    const string input = "(";
    Solution uut;

    const bool actual = uut.isValid(input);

    ASSERT_FALSE(actual);
}

TEST(ValidParentheses_Solution, isValid_OneClosingCharacter)
{
    const string input = ")";
    Solution uut;

    const bool actual = uut.isValid(input);

    ASSERT_FALSE(actual);
}