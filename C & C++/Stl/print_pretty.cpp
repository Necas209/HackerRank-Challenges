#include <iostream>
#include <iomanip>

int main()
{
	int t;
	std::cin >> t;
	std::cout << std::setiosflags(std::ios::uppercase);
	std::cout << std::setw(0xf) << std::internal;
	while (t--)
	{
		double a;
		std::cin >> a;
		double b;
		std::cin >> b;
		double c;
		std::cin >> c;
		std::cout << std::hex << std::left << std::showbase << std::nouppercase;
		std::cout << static_cast<long long>(a) << std::endl;
		std::cout << std::dec << std::right << std::setw(15) << std::setfill('_') << std::showpos << std::fixed << std::setprecision(2);
		std::cout << b << std::endl;
		std::cout << std::scientific << std::uppercase << std::noshowpos << std::setprecision(9);
		std::cout << c << std::endl;
	}
	return 0;
}