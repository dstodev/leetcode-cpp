#include <iostream>
#include <string>
#include <cstddef>

using std::cout;
using std::endl;
using std::string;
using std::size_t;

enum class Values {
    Zero,
    One,
    Two
};

template<Values value_T>
struct ToString {
};

template<>
struct ToString<Values::Zero> {
    static constexpr const char *name = "Zero";
};

template<>
struct ToString<Values::One> {
    static constexpr const char *name = "One";
};

template<>
struct ToString<Values::Two> {
    static constexpr const char *name = "Two";
};

template<Values value_T>
struct printer {
    printer() {
        cout << ToString<value_T>::name << endl;
    }
};

template<typename Enum_T, size_t Enum_N, size_t i, template<Enum_T> class visitor_T>
struct for_all_iterator {
    for_all_iterator() {
        visitor_T<static_cast<Enum_T>(i)>();
        for_all_iterator<Enum_T, Enum_N, i + 1, visitor_T>();
    }
};

template<typename Enum_T, size_t Enum_N, template<Enum_T> class visitor_T>
struct for_all_iterator<Enum_T, Enum_N, Enum_N, visitor_T> {
    // i == Enum_N; do nothing. Break recursion chain.
};

template<typename Enum_T, size_t Enum_N, template<Enum_T> class visitor_T>
struct for_all {
    for_all() {
        for_all_iterator<Enum_T, Enum_N, 0, visitor_T>();
    }
};

int main() {
    for_all<Values, 3, printer>();

    return 0;
}
