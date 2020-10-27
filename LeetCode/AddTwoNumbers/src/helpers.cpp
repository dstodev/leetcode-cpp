#include "given.hpp"

ListNode * createList(int val)
{
	return new ListNode(val);
}

bool operator==(const ListNode & l1, const ListNode & l2)
{
	bool is_equal = true;

	const ListNode * lhs = &l1;
	const ListNode * rhs = &l2;

	if (lhs != rhs) {
		// Somehow, the compiler will let a reference have a null address. This shouldn't be possible.
		// Nonetheless, check for their existence, because I guess it is possible.
		const bool equal_existence = (lhs == nullptr) == (rhs == nullptr);

		if (!equal_existence) {
			is_equal = false;
		}

		while (is_equal && lhs != nullptr && rhs != nullptr) {
			const bool equal_val = lhs->val == rhs->val;
			const bool equal_next_existence = (lhs->next == nullptr) == (rhs->next == nullptr);

            if (!equal_val || !equal_next_existence) {
                is_equal = false;
            }

            lhs = lhs->next;
			rhs = rhs->next;
		}
	}

	return is_equal;
}

void deleteList(ListNode * list)
{
	ListNode * node;

	while (list != nullptr) {
		node = list;
		list = list->next;

		delete node;
	}
}
