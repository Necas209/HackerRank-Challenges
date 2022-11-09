#include <cmath>
#include <iostream>

int main() {
    
	unsigned long long n = 100000000, s = 1232077670, p = 126810854, q = 1536183938;
	std::cin >> n >> s >> p >> q;

	unsigned long long i, a = s, ap = 0, k = 0;
    const unsigned long long a0 = s, v = static_cast<unsigned long long>(pow(2, 31));

	for (i = 0; i < n; i++) {
        a = a * p + q;
        a = a % v;
        if ((a == a0 || a == ap) && i != 0) {
            k = i + 1;
            break;
        }
        ap = a;
    }
    if (i == n) k = i;
	std::cout << k << std::endl;
    return 0;
}
