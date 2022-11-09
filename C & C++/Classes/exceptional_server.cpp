#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>


class server {
	static int load_;
public:
	static auto compute(const long long a, const long long b) {
		load_ += 1;
		if (a < 0) {
			throw std::invalid_argument("A is negative");
		}
		const std::vector v(a, 0);
		if (b == 0) throw 0;
		const auto real = a / b * -1;
		const int ans = v.at(b);
		return real + a - b * ans;
	}
	static int get_load() {
		return load_;
	}
};
int server::load_ = 0;

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		long long a, b;
		std::cin >> a >> b;
		try
		{
			std::cout << server::compute(a, b) << std::endl;
		}
		catch ([[maybe_unused]] const std::bad_alloc& bad)
		{
			std::cout << "Not enough memory\n";
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Other Exception\n";
		}
	}
	std::cout << server::get_load() << std::endl;
	return 0;
}