#include <sstream>
#include <vector>
#include <iostream>

std::vector<int> parse_ints(const std::string& str) {
	std::istringstream ss(str + ',');
	std::vector<int> vec;
	int num;
	char ch;
	while (ss >> num >> ch)
	{
		vec.push_back(num);
	}
	return vec;
}

int main() {
	std::string str;
	std::cin >> str;
	for (const auto num : parse_ints(str)) {
		std::cout << num << "\n";
	}
	return 0;
}
