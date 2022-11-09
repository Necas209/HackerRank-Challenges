#include <iostream>
#include <set>

int main() {
	std::set<int> s;
	int q;
	std::cin >> q;

	while (q--)
	{
		int y, x;
		std::cin >> y >> x;
		switch (y)
		{
		case 1:
			s.insert(x);
			break;
		case 2:
			s.erase(x);
			break;
		case 3:
			if (s.contains(x))
			{
				std::cout << "Yes\n";
			}
			else {
				std::cout << "No\n";
			}
			break;
		default:
			std::cout << "Query error.\n";
		}
	}
	return 0;
}