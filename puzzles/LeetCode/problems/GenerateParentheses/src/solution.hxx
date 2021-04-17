#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <unordered_set>

class Solution
{
public:
	static std::vector<std::string> generateParenthesis(int input)
	{
		auto permutations = getPermutations(static_cast<size_t>(input));
		return std::vector<std::string>(permutations.begin(), permutations.end());
	}

	static std::unordered_set<std::string> getPermutations(size_t num_rows)
	{
		std::unordered_set<std::string> permutations {"()"};
		std::unordered_set<std::string> intermediates;

		for (size_t i = 1; i < num_rows; ++i) {
			intermediates.clear();

			for (const std::string & root : permutations) {
				auto temp = scanInsert(root);
				intermediates.insert(temp.begin(), temp.end());
			}

			permutations = intermediates;
		}

		return permutations;
	}

	static std::unordered_set<std::string> scanInsert(const std::string & root)
	{
		std::unordered_set<std::string> set;

		for (size_t i = 0; i <= root.size(); ++i) {
			std::string item = root;
			item.insert(i, "()");
			set.insert(item);
		}

		return set;
	}
};

#endif  // SOLUTION_H
