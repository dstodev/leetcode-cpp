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

		int addend_left;
		int addend_right;
		int carry = 0;

		while (lhs || rhs) {
			addend_left = 0;
			addend_right = 0;

			if (lhs) {
				addend_left = lhs->val;
				lhs = lhs->next;
			}
			if (rhs) {
				addend_right = rhs->val;
				rhs = rhs->next;
			}

			int sum = addend_left + addend_right + carry;
			carry = sum / 10;
			sum %= 10;

			travel->val = sum;

			if (lhs || rhs) {
				travel->next = new ListNode;
				travel = travel->next;
			}
			else if (carry) {
				travel->next = new ListNode(carry);
			}
		}

		return answer;
	}
};

#endif  // SOLUTION_H
