#include <vector>
using std::vector;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(TwoSum_Solution, defaultConstructor)
{
	Solution uut;
	(void) uut;
}

TEST(TwoSum_Solution, twoSum_GivenInputExample1)
{
	const vector<int> expected {0, 1};
	const vector<int> nums {2, 7, 11, 15};
	const int target = 9;

	Solution uut;

	const vector<int> actual = uut.twoSum(nums, target);

	ASSERT_EQ(expected, actual);
}

TEST(TwoSum_Solution, twoSum_GivenInputExample2)
{
	const vector<int> expected {1, 2};
	const vector<int> nums {3, 2, 4};
	const int target = 6;

	Solution uut;

	const vector<int> actual = uut.twoSum(nums, target);

	ASSERT_EQ(expected, actual);
}

TEST(TwoSum_Solution, twoSum_GivenInputExample3)
{
	const vector<int> expected {0, 1};
	const vector<int> nums {3, 3};
	const int target = 6;

	Solution uut;

	const vector<int> actual = uut.twoSum(nums, target);

	ASSERT_EQ(expected, actual);
}
