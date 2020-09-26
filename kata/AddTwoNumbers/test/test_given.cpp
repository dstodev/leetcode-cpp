#include <gtest/gtest.h>

#include <given.hpp>


TEST(GivenListNode, defaultConstructor)
{
	ListNode uut;

	ASSERT_EQ(0, uut.val);
	ASSERT_EQ(nullptr, uut.next);
}


TEST(GivenListNode, oneArgConstructor)
{
	ListNode uut(1);

	ASSERT_EQ(1, uut.val);
	ASSERT_EQ(nullptr, uut.next);
}

TEST(GivenListNode, twoArgConstructor)
{
	ListNode expected;
	ListNode uut(2, &expected);

	ASSERT_EQ(2, uut.val);
	ASSERT_EQ(&expected, uut.next);
}
