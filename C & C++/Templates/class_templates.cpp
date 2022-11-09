#include <utility>
#include <vector>
#include <iostream>

# define concatenate add

template<typename T>
class AddElements {
    T element;

public:
    explicit AddElements(T el) : element(std::move(el)) {}

    T add(const T &el) {
        element += el;
        return element;
    }
};

int main() {
    int n, i;
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::string type;
        std::cin >> type;
        if (type == "float") {
            double element1, element2;
            std::cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            std::cout << myfloat.add(element2) << std::endl;
        } else if (type == "int") {
            int element1, element2;
            std::cin >> element1 >> element2;
            AddElements<int> myint(element1);
            std::cout << myint.add(element2) << std::endl;
        } else if (type == "string") {
            std::string element1, element2;
            std::cin >> element1 >> element2;
            AddElements<std::string> mystring(element1);
            std::cout << mystring.concatenate(element2) << std::endl;
        }
    }
    return 0;
}
