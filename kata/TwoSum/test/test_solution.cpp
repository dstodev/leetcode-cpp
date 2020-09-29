#include <vector>
using std::vector;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(TwoSum_Solution, defaultConstructor)
{
	Solution uut;
}

TEST(TwoSum_Solution, twoSumGivenInputExampleOne)
{
	vector<int> expected{0, 1};
	vector<int> nums{2, 7, 11, 15};
	int target = 9;

	Solution uut;

	vector<int> actual = uut.twoSum(nums, target);

	ASSERT_EQ(expected, actual);
}

TEST(TwoSum_Solution, twoSumGivenInputExampleTwo)
{
	vector<int> expected{1, 2};
	vector<int> nums{3, 2, 4};
	int target = 6;

	Solution uut;

	vector<int> actual = uut.twoSum(nums, target);

	ASSERT_EQ(expected, actual);
}

TEST(TwoSum_Solution, twoSumGivenInputExampleThree)
{
	vector<int> expected{0, 1};
	vector<int> nums{3, 3};
	int target = 6;

	Solution uut;

	vector<int> actual = uut.twoSum(nums, target);

	ASSERT_EQ(expected, actual);
}
