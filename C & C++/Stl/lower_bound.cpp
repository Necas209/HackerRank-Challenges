#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> vec;
	while (n--)
	{
		int i;
		std::cin >> i;
		vec.push_back(i);
	}
	std::cin >> n;
	std::vector<int> queries;
	while (n--)
	{
		int i;
		std::cin >> i;
		queries.push_back(i);
	}
	for (int query : queries)
	{
		if (auto it = std::ranges::lower_bound(vec, query);
			*(it + 1) == query || *it == query)
		{
			std::cout << "Yes " << std::distance(vec.begin(), it) + 1 << std::endl;
		}
		else
		{
			std::cout << "No " << std::distance(vec.begin(), it) + 1 << std::endl;
		}
	}
	return 0;
}