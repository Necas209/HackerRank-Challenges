#include <iostream>
#include <stdexcept>

int largest_proper_divisor(const int n)
{
	if (n == 0)
	{
		throw std::invalid_argument("largest proper divisor is not defined for n=0");
	}
	if (n == 1)
	{
		throw std::invalid_argument("largest proper divisor is not defined for n=1");
	}
	for (int i = n / 2; i >= 1; --i)
	{
		if (n % i == 0)
		{
			return i;
		}
	}
	return -1; // will never happen
}

void process_input(const int n)
{
	try
	{
		const int d = largest_proper_divisor(n);
		std::cout << "result=" << d << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "returning control flow to caller" << std::endl;
}

int main()
{
	int n;
	std::cin >> n;
	process_input(n);
	return 0;
}