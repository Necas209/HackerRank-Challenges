#include <iostream>
#include <set>
#include <map>

int main()
{
	std::map<std::string, int> marks;
	int q;
	std::cin >> q;
	while (q--)
	{
		int type;
		std::cin >> type;
		std::string x;
		int y;
		switch (type)
		{
		case 1:
			std::cin >> x >> y;
			if (marks.contains(x))
				marks[x] += y;
			else
				marks.insert(std::make_pair(x, y));
			break;
		case 2:
			std::cin >> x;
			marks.erase(x);
			break;
		case 3:
			std::cin >> x;
			if (marks.contains(x))
				std::cout << marks[x] << std::endl;
			else
				std::cout << "0\n";
			break;
		default:
			std::cout << "Query type unavailable.\n";
		}
	}
	return 0;
}