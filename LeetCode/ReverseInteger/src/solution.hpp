#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>


class Solution
{
public:
	int reverse(int input)
	{
		int answer = 0;
		int digit;

		do {
			digit = input % 10;

			// Clamp overflow digit to [0 < digit < int::max]. Negative digit cannot contribute to overflow,
			// but would otherwise overflow int::max when subtracted from it.
			const int overflow_digit = std::max(0, digit);

			// Clamp underflow digit to [int::min < digit < 0]. Positive digit cannot contribute to
			// underflow, but would otherwise underflow int::min when added to it.
			const int underflow_digit = std::min(0, digit);

			// answer * 10 could overflow, so we instead divide the other side by 10 to achieve the same
			// effect:
			//
			// answer * 10 + digit > int::max == answer > (int::max - digit) / 10
			// answer * 10 + digit < int::min == answer < (int::min - digit) / 10
			// ^^^^^^^^^^^^^^^^^^^                        ^^^^^^^^^^^^^^^^^^^^^^^
			//   could overflow                               cannot overflow
			const bool will_overflow = answer > ((std::numeric_limits<int>::max() - overflow_digit) / 10);
			const bool will_underflow = answer < ((std::numeric_limits<int>::min() - underflow_digit) / 10);

			// How can this logic be tested? I'd like to test:
			// 1. An integer which will not overflow after `answer * 10`, but will overflow with `+ digit`.
			// This doesn't seem possible, because int::max is 2147483647. I'd want to use 8463847412,
			// because backwards it is int::max + 1, but that number is far greater than int::max, so it
			// cannot be passed to this function without overflowing.

			if (will_overflow || will_underflow) {
				answer = 0;
				break;
			}

			answer = answer * 10 + digit;

		} while (input /= 10);

		return answer;
	}
};

#endif  // SOLUTION_H
