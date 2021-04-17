#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

class Solution
{
public:
	std::vector<int> twoSum(const std::vector<int> & nums, int target)
	{
		std::vector<int> answer;

		for (auto it = nums.begin(); it < nums.end(); ++it) {
			int delta = target - *it;
			auto delta_it = find(nums.begin(), nums.end(), delta);

			if (delta_it == it) {
				delta_it = find(++delta_it, nums.end(), delta);
			}

			if (delta_it != nums.end()) {
				answer.emplace_back(static_cast<int>(it - nums.begin()));
				answer.emplace_back(static_cast<int>(delta_it - nums.begin()));
				break;
			}
		}

		return answer;
	}
};

#endif  // SOLUTION_H
