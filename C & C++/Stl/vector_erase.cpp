#include <vector>
#include <iostream>

int main() {
	std::vector<int> v;
	int n;
	std::cin >> n;
	while (n--)
	{
		int i;
		std::cin >> i;
		v.push_back(i);
	}
	int x, a, b;
	std::cin >> x;
	v.erase(v.begin() + x - 1);
	std::cin >> a >> b;
	v.erase(v.begin() + a - 1, v.begin() + b - 1);
	std::cout << v.size() << std::endl;
	for (const auto i : v)
	{
		std::cout << i << ' ';
	}
	return 0;
}
