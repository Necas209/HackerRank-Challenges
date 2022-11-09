#include <iostream>
#include <string>

int main() {
	std::string a, b;
	std::cin >> a >> b;
	std::cout << a.size() << ' ' << b.size() << std::endl;
	std::cout << a + b << std::endl;

	const char ch = a[0];
	a[0] = b[0];
	b[0] = ch;
	std::cout << a << ' ' << b << std::endl;
	return 0;
}