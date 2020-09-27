#ifndef HELPERS_H
#define HELPERS_H

#include "given.hpp"


inline ListNode * createList(int val);

template <typename... Args>
inline ListNode * createList(int val, Args... args)
{
	return new ListNode(val, createList(args...));
}

bool operator==(const ListNode & l1, const ListNode & l2);

void deleteList(ListNode * list);

#endif  // HELPERS_H
