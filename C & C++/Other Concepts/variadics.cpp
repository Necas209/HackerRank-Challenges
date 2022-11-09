#include <iostream>

// Enter your code for reversed_binary_value<bool...>()
template <bool A>
int reversed_binary_value()
{
	return A;
}

template <bool A, bool B, bool... D>
int reversed_binary_value()
{
	return (reversed_binary_value<B, D...>() << 1) + A;
}

template <int N, bool...Digits>
struct check_values {
	static void check(int x, int y)
	{
		check_values<N - 1, false, Digits...>::check(x, y);
		check_values<N - 1, true, Digits...>::check(x, y);
	}
};

template <bool...Digits>
struct check_values<0, Digits...> {
	static void check(const int x, const int y)
	{
		const int z = reversed_binary_value<Digits...>();
		std::cout << (z + 64 * y == x);
	}
};

int main()
{
	int t; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int x, y;
		std::cin >> x >> y;
		check_values<6>::check(x, y);
		std::cout << '\n';
	}
}