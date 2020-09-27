#include <gtest/gtest.h>

#include <helpers.hpp>
#include <solution.hpp>

TEST(Solution, defaultConstructor)
{
	Solution uut;
}

TEST(Solution, addTwoNumbersGivenInput)
{
	auto l1 = createList(2, 4, 3);
	auto l2 = createList(5, 6, 4);
	auto expected = createList(7, 0, 8);

	Solution solver;
	auto actual = solver.addTwoNumbers(l1, l2);

	ASSERT_EQ(*expected, *actual);

	deleteList(l1);
	deleteList(l2);
	deleteList(expected);
	deleteList(actual);
}

TEST(Solution, addTwoNumbersInequalArgCount)
{
	auto l1 = createList(1, 2, 3, 4);
	auto l2 = createList(5, 6);
	auto expected = createList(6, 8, 3, 4);

	Solution solver;
	auto actual = solver.addTwoNumbers(l1, l2);

	ASSERT_EQ(*expected, *actual);

	deleteList(l1);
	deleteList(l2);
	deleteList(expected);
	deleteList(actual);
}

TEST(Solution, addOneArgWithCarry)
{
	auto l1 = createList(5);
	auto l2 = createList(5);
	auto expected = createList(0, 1);

	Solution solver;
	auto actual = solver.addTwoNumbers(l1, l2);

	ASSERT_EQ(*expected, *actual);

	deleteList(l1);
	deleteList(l2);
	deleteList(expected);
	deleteList(actual);
}
