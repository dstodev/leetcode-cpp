#ifndef SOLUTION_H
#define SOLUTION_H

#include <stack>
using std::stack;

#include <queue>
using std::queue;


class Solution
{
public:
	bool isPalindrome(int x)
	{
		// Ideas:
		//
		//    Challenge: Do not use string functions!
		//
		//    If the number is negative, return false.
		//    Read digits from the integer via modulo 10. Add each integer to a stack and a queue.
		//    Pop each value from queue/stack in pairs and compare them. If they all match, the number is a palindrome.
		//
		//    Calculate the quantity of digits in the number (e.g. Log10(number) + 1)
		//    Compare indices offset from the front and the back the number:
		//
		//        NNNNNNN  ->  NNNNNNN  ->  NNNNNNN  ->  NNNNNNN
		//        ^     ^       ^   ^         ^ ^           ^

		bool status = true;

		stack<int> digits_lifo;
		queue<int> digits_fifo;

		if (x < 0) {
			status = false;
		}
		else {
			while (x) {
				int digit = x % 10;
				x /= 10;

				digits_lifo.push(digit);
				digits_fifo.push(digit);
			}
			while (status && !digits_lifo.empty()) {
				if (digits_lifo.top() != digits_fifo.front()) {
					status = false;
				}
				digits_lifo.pop();
				digits_fifo.pop();
			}
		}

		return status;
	}
};

#endif  // SOLUTION_H
