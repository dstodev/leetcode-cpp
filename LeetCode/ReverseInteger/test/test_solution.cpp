#include <string>
using std::string;

#include <gtest/gtest.h>

#include <solution.hpp>


TEST(ReverseInteger_Solution, defaultConstructor)
{
    Solution uut;
}

TEST(ReverseInteger_Solution, reverseGivenInputExample1)
{
    int input = 123;
    int expected = 321;

    Solution uut;

    int actual = uut.reverse(input);

    ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverseGivenInputExample2)
{
    int input = -123;
    int expected = -321;

    Solution uut;

    int actual = uut.reverse(input);

    ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverseGivenInputExample3)
{
    int input = 120;
    int expected = 21;

    Solution uut;

    int actual = uut.reverse(input);

    ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverseGivenInputExample4)
{
    int input = 0;
    int expected = 0;

    Solution uut;

    int actual = uut.reverse(input);

    ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverseZeroInMiddleOfNumber)
{
    int input = 901;
    int expected = 109;

    Solution uut;

    int actual = uut.reverse(input);

    ASSERT_EQ(expected, actual);
}

TEST(ReverseInteger_Solution, reverseMultiply10Overflow)
{
    int input = 1000000009;
    int expected = 0;

    Solution uut;

    int actual = uut.reverse(input);

    ASSERT_EQ(expected, actual);
}
