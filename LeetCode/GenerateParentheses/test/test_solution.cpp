#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::is_permutation;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(GenerateParentheses_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(GenerateParentheses_Solution, generateParenthesis_GivenInputExample1)
{
	const int input = 3;
	const vector<string> expected {"((()))", "(()())", "(())()", "()(())", "()()()"};

	const vector<string> actual = Solution::generateParenthesis(input);

	ASSERT_EQ(expected.size(), actual.size());
	ASSERT_TRUE(is_permutation(expected.begin(), expected.end(), actual.begin()));
}

TEST(GenerateParentheses_Solution, generateParenthesis_GivenInputExample2)
{
	const int input = 1;
	const vector<string> expected {"()"};

	const vector<string> actual = Solution::generateParenthesis(input);

	ASSERT_EQ(expected.size(), actual.size());
	ASSERT_TRUE(is_permutation(expected.begin(), expected.end(), actual.begin()));
}
