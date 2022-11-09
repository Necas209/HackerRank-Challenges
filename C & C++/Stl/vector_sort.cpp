#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	std::vector<int> vec;
	int n;
	std::cin >> n;
	while (n--)
	{
		int v;
		std::cin >> v;
		vec.push_back(v);
	}
	std::ranges::sort(vec);
	for (const auto v : vec)
	{
		std::cout << v << ' ';
	}
	return 0;
}