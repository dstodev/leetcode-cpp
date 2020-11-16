#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <unordered_set>


class Solution
{
public:
	static std::vector<std::string> generateParenthesis(int input)
	{
		auto permutations = populatePermutations(static_cast<size_t>(input));
		return std::vector<std::string>(permutations.begin(), permutations.end());
	}

	static std::unordered_set<std::string> populatePermutations(size_t num_rows)
	{
		std::unordered_set<std::string> permutations;
		std::string permutation;

		for (size_t i = 0; i < num_rows; ++i) {
			permutation = "()";
			permutations.insert(permutation);
		}

		return permutations;
	}

	static std::unordered_set<std::string> scanInsert(const std::string & input)
	{
		std::unordered_set<string> set;

		for (size_t i = 0; i <= input.size(); ++i) {
			std::string item = input;
			item.insert(i, "()");
			set.insert(item);
		}

		return set;
	}
};

#endif  // SOLUTION_H
