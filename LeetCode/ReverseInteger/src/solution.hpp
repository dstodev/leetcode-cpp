#ifndef SOLUTION_H
#define SOLUTION_H


class Solution
{
public:
	int reverse(int input)
	{
		int answer = 0;
		int digit;

		do {
			const bool will_overflow  = answer > (std::numeric_limits<int>::max() / 10);
			const bool will_underflow = answer < (std::numeric_limits<int>::min() / 10);

			if (will_overflow || will_underflow) {
				// Return 0 instead.
				answer = 0;
				break;
			}
			else {
				digit = input % 10;
				answer = answer * 10 + digit;
			}
		} while (input /= 10);

		return answer;
	}
};

#endif  // SOLUTION_H
