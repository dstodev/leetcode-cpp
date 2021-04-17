#include "solution.hxx"
#include <cmath>
#include <queue>
#include <stack>

using std::abs;
using std::log10;
using std::pow;
using std::queue;
using std::stack;

// Switch to only include & use <deque>?


namespace {

// template <typename T>
// concept Arithmetic = std::is_arithmetic<T>::value;

/**
 * @brief Get the number of digits in @p value.
 *
 * @param[in] value Integer to count
 * @return Number of digits in @p value.
 */
inline int numDigits(int value)
{
	if (value) {
		// Ensure the value to count is positive
		value = abs(value);

		// Cast the result of Log10(value) to an int to intentially truncate the decimal portion.
		// Add one afterwards.
		//
		//    e.g.:
		//      Log10(9) = 0.95   ->  truncate decimal  ->  0  -> add one  ->  1
		//      Log10(10) = 1     ->                    ->  1  ->          ->  2
		//      Log10(11) = 1.04  ->                    ->  1  ->          ->  2
		//
		value = static_cast<int>(log10<int>(value)) + 1;
	}
	else {
		// If value is 0, return 1. This is because LogN(0) is undefined.
		value = 1;
	}

	return value;
}

/**
 * @brief Get digit @p index from integer @p value .
 * @details Extract digit at @p index (right-to-left).
 *
 * @param value Integer to extract from
 * @param index Index of integer to extract
 * @return Integer at position @p index of @p value .
 */
inline int extractDigit(int value, int index)
{
	// To get integer at index N, divide the value by 10^index, then modulo by 10.
	//
	//    e.g.:
	//      extractDigit(12345, 1)
	//      12345  ->  divide by 10^1 (10)    ->  1234.5  ->  modulo 10  ->  4  (4.5 truncated to 4)
	//         ^
	//
	//      extractDigit(12345, 3)
	//      12345  ->  divide by 10^3 (1000)  ->  12.345  ->  modulo 10  ->  2  (2.345 truncated to 2)
	//       ^
	//
	const int mask = static_cast<int>(pow(10, index));
	value = abs(value);
	value = value / mask % 10;
	return value;
}

bool isPalindromeStrategyOne(int x)
{
	/*
	    If the number is negative, return false.
	    Read digits from the integer via modulo 10. Add each integer to a stack and a queue.
	    Pop each value from queue/stack in pairs and compare them. If they all match, the number is a palindrome.
	*/

	bool is_palindrome = true;

	stack<int> digits_lifo;
	queue<int> digits_fifo;

	if (x < 0) {
		is_palindrome = false;
	}
	else {
		while (x) {
			int digit = x % 10;
			x /= 10;

			digits_lifo.push(digit);
			digits_fifo.push(digit);
		}
		while (is_palindrome && !digits_lifo.empty()) {
			if (digits_lifo.top() != digits_fifo.front()) {
				is_palindrome = false;
			}
			digits_lifo.pop();
			digits_fifo.pop();
		}
	}

	return is_palindrome;
}

bool isPalindromeStrategyTwo(int x)
{
	/*
	    Calculate the quantity of digits in the number (e.g. Log10(number) + 1)
	    Compare indices offset from the front and the back the number:

	        NNNNNNN  ->  NNNNNNN  ->  NNNNNNN  ->  NNNNNNN
	        ^     ^       ^   ^         ^ ^           ^
	*/

	bool is_palindrome = true;
	const int num_digits = numDigits(x);

	if (x < 0) {
		is_palindrome = false;
	}

	for (int i = 0; is_palindrome && i < num_digits; ++i) {
		if (extractDigit(x, i) != extractDigit(x, num_digits - i - 1)) {
			is_palindrome = false;
		}
	}

	return is_palindrome;
}

}  // namespace


bool Solution::isPalindrome(int x)
{
	// Challenge: Do not use string functions!

	return isPalindromeStrategyTwo(x);
}
