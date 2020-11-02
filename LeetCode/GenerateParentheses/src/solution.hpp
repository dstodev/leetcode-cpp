#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <vector>


class Solution
{
public:
	static std::vector<std::string> generateParenthesis(int input)
	{
		std::vector<std::string> permutations;

		permutations.emplace_back("()");

		return permutations;
	}
};

#endif  // SOLUTION_H
