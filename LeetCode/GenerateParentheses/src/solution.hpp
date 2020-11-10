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

		/*
		 * n = 3
		 *
		 * ((()))
		 * (())()
		 * ()(())
		 * ()()()
		 * (()())
		 *
		 * Pivot?
		 * ((()))
		 *   ^
		 * (())()
		 *  ^
		 * ()(())
		 * ^
		 *
		 * Recursive?
		 * (()())
		 *
		 * Graph permutations
		 * Each node is a pair of parentheses, and they can contain other nodes to implement nesting.
		 */

		permutations.emplace_back("()");

		return permutations;
	}
};

#endif  // SOLUTION_H
