#ifndef SOLUTION_H
#define SOLUTION_H


#include <string>

class Solution
{
public:
	static int romanToInt(const std::string & input)
	{
		int value = 0;
		auto it = input.begin();

		while (it < input.end()) {
			std::string token = getNextToken(it, input.end());
			value += mapTokenToUint(token);
		}

		return value;
	}

	static std::string getNextToken(std::string::const_iterator & it, const std::string::const_iterator & end)
	{
		std::string token;

		if (it < end) {
			switch (*it) {
			case 'I':
				// (I(?:I{1,2}|V|X)?)
				token = *it++;
				if (it < end && (*it == 'V' || *it == 'X')) {
					token += *it++;
				}
				else {
					for (int i = 0; it < end && *it == 'I' && i < 2; ++i) {
						token += *it++;
					}
				}
				break;

			case 'X':
				// (X(?:L|C)?)
				token = *it++;
				if (it < end && (*it == 'L' || *it == 'C')) {
					token += *it++;
				}
				break;

			case 'C':
				// (C(:?:D|M)?)
				token = *it++;
				if (it < end && (*it == 'D' || *it == 'M')) {
					token += *it++;
				}
				break;

			case 'V':
			case 'L':
			case 'D':
			case 'M':
				token = *it++;
				break;

			default:
				break;
			}
		}

		return token;
	}

	static int mapTokenToUint(const std::string & token)
	{
		int value = 0;

		if (token == "I") {
			value = 1;
		}
		else if (token == "II") {
			value = 2;
		}
		else if (token == "III") {
			value = 3;
		}
		else if (token == "IV") {
			value = 4;
		}
		else if (token == "V") {
			value = 5;
		}
		else if (token == "IX") {
			value = 9;
		}
		else if (token == "X") {
			value = 10;
		}
		else if (token == "XL") {
			value = 40;
		}
		else if (token == "L") {
			value = 50;
		}
		else if (token == "XC") {
			value = 90;
		}
		else if (token == "C") {
			value = 100;
		}
		else if (token == "CD") {
			value = 400;
		}
		else if (token == "D") {
			value = 500;
		}
		else if (token == "CM") {
			value = 900;
		}
		else if (token == "M") {
			value = 1000;
		}
		else {
			value = -1;
		}

		return value;
	}
};

#endif  // SOLUTION_H
