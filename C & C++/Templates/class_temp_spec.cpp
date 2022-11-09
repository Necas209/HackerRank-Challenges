#include <iostream>

enum class Fruit {
    apple,
    orange,
    pear
};
enum class Color {
    red,
    green,
    orange
};

template<typename T>
struct Traits;

// Define specializations for the Traits class template here.

template<typename T>
struct Traits {
    static const std::string NAMES[];

public:
    static std::string name(int index) {
        if (index < 0 || index >= (sizeof NAMES / sizeof NAMES[0]))
            return "unknown";
        return NAMES[index];
    }
};

template<>
const std::string Traits<Fruit>::NAMES[]{"apple", "orange", "pear"};

template<>
const std::string Traits<Color>::NAMES[]{"red", "green", "orange"};

int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i != t; ++i) {
        int index1;
        std::cin >> index1;
        int index2;
        std::cin >> index2;
        std::cout << Traits<Color>::name(index1) << " ";
        std::cout << Traits<Fruit>::name(index2) << "\n";
    }
}
