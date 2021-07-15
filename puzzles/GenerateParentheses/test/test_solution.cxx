#include <algorithm>
#include <gtest/gtest.h>
#include <solution.hxx>
#include <string>
#include <unordered_set>
#include <vector>

using std::is_permutation;
using std::string;
using std::unordered_set;
using std::vector;


TEST(GenerateParentheses_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(GenerateParentheses_Solution, generateParenthesis_givenInputExample1)
{
	const int input = 3;
	const vector<string> expected {"((()))", "(()())", "(())()", "()(())", "()()()"};

	const vector<string> actual = Solution::generateParenthesis(input);

	ASSERT_EQ(expected.size(), actual.size());
	ASSERT_TRUE(is_permutation(expected.begin(), expected.end(), actual.begin()));
}

TEST(GenerateParentheses_Solution, generateParenthesis_givenInputExample2)
{
	const int input = 1;
	const vector<string> expected {"()"};

	const vector<string> actual = Solution::generateParenthesis(input);

	ASSERT_EQ(expected.size(), actual.size());
	ASSERT_TRUE(is_permutation(expected.begin(), expected.end(), actual.begin()));
}

TEST(GenerateParentheses_Solution, getPermutations_n1)
{
	const size_t input = 1;
	const unordered_set<string> expected {"()"};

	const unordered_set<string> actual = Solution::getPermutations(input);

	ASSERT_EQ(expected, actual);
}

TEST(GenerateParentheses_Solution, getPermutations_n2)
{
	const size_t input = 2;
	const unordered_set<string> expected {"()()", "(())"};

	const unordered_set<string> actual = Solution::getPermutations(input);

	ASSERT_EQ(expected, actual);
}

TEST(GenerateParentheses_Solution, getPermutations_n3)
{
	const size_t input = 3;
	const unordered_set<string> expected {"()()()", "()(())", "(())()", "(()())", "((()))"};

	const unordered_set<string> actual = Solution::getPermutations(input);

	ASSERT_EQ(expected, actual);
}

TEST(GenerateParentheses_Solution, scanInsert_emptyString)
{
	const string input = "";
	const unordered_set<string> expected {"()"};

	const unordered_set<string> actual = Solution::scanInsert(input);

	ASSERT_EQ(expected, actual);
}

TEST(GenerateParentheses_Solution, scanInsert_onePair)
{
	const string input = "()";
	const unordered_set<string> expected {"()()", "(())"};

	const unordered_set<string> actual = Solution::scanInsert(input);

	ASSERT_EQ(expected, actual);
}

TEST(GenerateParentheses_Solution, scanInsert_twoPairVariantOne)
{
	const string input = "()()";
	const unordered_set<string> expected {"()()()", "()(())", "(())()"};

	const unordered_set<string> actual = Solution::scanInsert(input);

	ASSERT_EQ(expected, actual);
}

TEST(GenerateParentheses_Solution, scanInsert_twoPairVariantTwo)
{
	const string input = "(())";
	const unordered_set<string> expected {"(())()", "(()())", "((()))", "()(())"};

	const unordered_set<string> actual = Solution::scanInsert(input);

	ASSERT_EQ(expected, actual);
}
