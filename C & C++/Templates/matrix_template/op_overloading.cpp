#include <iostream>
#include "matrix.h"

int main() {
    int cases, n, m;
    std::cin >> cases;
    for (int k = 0; k < cases; k++) {
        // Read matrix 'x'
        std::cin >> n >> m;
        matrix<int> x(n, m);
        std::cin >> x;
        // Read matrix 'y'
        std::cin >> n >> m;
        matrix<int> y(n, m);
        std::cin >> y;
        // Compute sum and print it
        auto result = x + y;
        std::cout << result;
    }
    return 0;
}