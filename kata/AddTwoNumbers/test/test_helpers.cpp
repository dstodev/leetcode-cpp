#include <gtest/gtest.h>

#include <helpers.hpp>


TEST(Helpers, createListBase)
{
	ListNode * uut = createList(1);

	ASSERT_NE(nullptr, uut);
	ASSERT_EQ(1, uut->val);
	ASSERT_EQ(nullptr, uut->next);

	deleteList(uut);
}

TEST(Helpers, createListTwoArgs)
{
	ListNode * expected = new ListNode(1, new ListNode(2, nullptr));
	ListNode * actual = createList(1, 2);

	ASSERT_NE(nullptr, actual);
	ASSERT_EQ(expected->val, actual->val);
	ASSERT_EQ(expected->next->val, actual->next->val);

	deleteList(expected);
	deleteList(actual);
}

TEST(Helpers, ListNodeOperatorEqualAddressEqual)
{
	ListNode * l1 = createList(1, 2);

	ASSERT_TRUE(*l1 == *l1);

	deleteList(l1);
}

TEST(Helpers, ListNodeOperatorCompareNullptr)
{
	ListNode * l1 = createList(1, 2);

	// Why is this allowed?
	ASSERT_FALSE(*l1 == *static_cast<ListNode*>(nullptr));

	deleteList(l1);
}

TEST(Helpers, ListNodeOperatorEqualTwoArgsEqual)
{
	ListNode * l1 = createList(1, 2);
	ListNode * l2 = createList(1, 2);

	ASSERT_TRUE(*l1 == *l2);

	deleteList(l1);
	deleteList(l2);
}

TEST(Helpers, ListNodeOperatorEqualTwoArgsInequal)
{
	ListNode * l1 = createList(1, 2);
	ListNode * l2 = createList(3, 4);

	ASSERT_FALSE(*l1 == *l2);

	deleteList(l1);
	deleteList(l2);
}

TEST(Helpers, ListNodeOperatorEqualDifferentArgCount)
{
	ListNode * l1 = createList(1, 2);
	ListNode * l2 = createList(1, 2, 3);

	ASSERT_FALSE(*l1 == *l2);

	deleteList(l1);
	deleteList(l2);
}
