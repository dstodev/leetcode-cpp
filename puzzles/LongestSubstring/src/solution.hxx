#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <unordered_map>

class Solution
{
public:
	std::string::iterator head;
	std::string::iterator tail;

	int answer = 0;

	int lengthOfLongestSubstring(std::string input)
	{
		std::unordered_map<char, std::string::iterator> map;

		for (head = tail = input.begin(); head < input.end(); ++head) {
			// Increment head until there is a duplicate character, and record size. then:
			// Increment tail until there is not a duplicate character, and repeat.
			//
			// Ideas:
			//
			//    Get new character.
			//    Find that character in the string.
			//    If its location is the new character, no duplicates.
			//    If its location is elsewhere, set tail to right after that position.
			//
			//    Get new character.
			//    Store new character in map as K: character, V: index.
			//    If character is in hash map already, it is a duplicate:
			//    Set tail to its stored index, update index to new character.

			auto pair = map.emplace(*head, head);
			const bool is_duplicate = !pair.second;

			if (is_duplicate) {
				setSizeIfLarger();

				const auto map_index = pair.first;
				auto & char_index = map_index->second;

				if (tail < char_index + 1) {
					tail = char_index + 1;
				}

				char_index = head;
			}
		}

		setSizeIfLarger();

		return answer;
	}

	inline void setSizeIfLarger()
	{
		const int size = static_cast<int>(head - tail);

		if (size > answer) {
			answer = size;
		}
	}
};

#endif  // SOLUTION_H
