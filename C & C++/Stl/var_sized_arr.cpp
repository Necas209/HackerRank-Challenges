#include <iostream>
#include <algorithm>

int main()
{
	int n, n_q, ki;
	std::cin >> n >> n_q;
	const auto v = new int* [n];
	const auto q = new std::pair<int, int>[n_q];
	for (int i = 0; i < n; i++)
	{
		std::cin >> ki;
		v[i] = new int[ki];
		for (int j = 0; j < ki; j++)
		{
			std::cin >> v[i][j];
		}
	}
	for (int i = 0; i < n_q; i++)
	{
		std::cin >> q[i].first >> q[i].second;
	}
	for (int i = 0; i < n_q; i++)
	{
		std::cout << v[q[i].first][q[i].second] << std::endl;
	}
	return 0;
}
