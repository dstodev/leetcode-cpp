#ifndef SOLUTION_H
#define SOLUTION_H

#include "given.hpp"

class Solution
{
public:
	ListNode * addTwoNumbers(ListNode * lhs, ListNode * rhs)
	{
		ListNode * answer = new ListNode;
		ListNode * travel = answer;
		int carry = 0;

		while (lhs || rhs) {
			int addend_left = lhs ? lhs->val : 0;
			int addend_right = rhs ? rhs->val : 0;

			int sum = addend_left + addend_right + carry;
			carry = sum / 10;
			sum %= 10;

			travel->val = sum;

			if ((lhs && lhs->next) || (rhs && rhs->next)) {
				travel->next = new ListNode;
				travel = travel->next;
			}
			else if (carry) {
				travel->next = new ListNode(carry);
			}

			lhs = lhs ? lhs->next : nullptr;
			rhs = rhs ? rhs->next : nullptr;
		}

		return answer;
	}
};

#endif  // SOLUTION_H
