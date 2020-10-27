#ifndef SOLUTION_H
#define SOLUTION_H


#include <stack>
#include <string>

class Solution
{
public:
	static bool isValid(const std::string& input)
	{
		bool valid = false;
		std::stack<char> braces;

		for (char brace : input) {
			char target = '\0';
            valid = false;

			switch (brace) {
			case '(':
			case '[':
			case '{':
				braces.push(brace);
				valid = true;
				break;

			case '}':
				target = '{';
                break;

			case ']':
				target = '[';
                break;

			case ')':
				target = '(';
				break;

			default:
				break;
			}

            if (!braces.empty() && braces.top() == target) {
                braces.pop();
                valid = true;
            }

			if (!valid) {
				break;
			}
		}

		if (!braces.empty()) {
			valid = false;
		}

		return valid;
	}
};

#endif  // SOLUTION_H
