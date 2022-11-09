#include <iostream>
#include <string>
#include <sstream>
#include <exception>

class bad_length_exception final
	: public std::exception
{
	size_t n_;
	mutable std::string msg_;
public:
	explicit bad_length_exception(const size_t n)
	{
		this->n_ = n;
		msg_ = std::to_string(n);
	}

	const char* what() const noexcept override
	{
		return msg_.c_str();
	}
};


bool check_username(const std::string& username) {
	bool is_valid = true;
	const auto n = username.length();
	if (n < 5) {
		throw bad_length_exception(n);
	}
	for (size_t i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			is_valid = false;
		}
	}
	return is_valid;
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		std::string username;
		std::cin >> username;
		try {
			if (check_username(username)) {
				std::cout << "Valid" << '\n';
			}
			else {
				std::cout << "Invalid" << '\n';
			}
		}
		catch (bad_length_exception& e) {
			std::cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}