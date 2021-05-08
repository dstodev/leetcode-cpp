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
    Two,
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

template<Values value_T>
struct printer_with_arguments {
    explicit printer_with_arguments(int value) {
        cout << ToString<value_T>::name << ' ' << value << endl;
    }
};

template<typename Enum_T, size_t Enum_N, size_t i, template<Enum_T> class Visitor_T, typename... Args_T>
struct for_all_iterator {
    explicit for_all_iterator(Args_T...args) {
        Visitor_T<static_cast<Enum_T>(i)>(args...);
        for_all_iterator<Enum_T, Enum_N, i + 1, Visitor_T, Args_T...>(args...);
    }
};

template<typename Enum_T, size_t Enum_N, template<Enum_T> class Visitor_T, typename... Args_T>
struct for_all_iterator<Enum_T, Enum_N, Enum_N, Visitor_T, Args_T...> {
    explicit for_all_iterator(Args_T...) {
        /* i == Enum_N; do nothing. Break recursion chain. */
    }
};

template<typename Enum_T, size_t Enum_N, template<Enum_T> class Visitor_T>
struct for_all {
    template <typename... Args_T>
    explicit for_all(Args_T...args) {
        for_all_iterator<Enum_T, Enum_N, 0, Visitor_T, Args_T...>(args...);
    }
};

int main() {
    int a = 5;

    for_all<Values, 3, printer>{};
    for_all<Values, 3, printer_with_arguments>{a};

    return 0;
}
