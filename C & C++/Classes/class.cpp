#include <iostream>
#include <sstream>

namespace class_ex
{
	class student
	{
		int age_;
		int standard_;
		std::string first_name_;
		std::string last_name_;
	public:
		student() {
			age_ = 18;
			standard_ = 0;
		}
		student(const int a, const int s, const std::string& f, const std::string& l) {
			age_ = a;
			standard_ = s;
			first_name_ = f;
			last_name_ = l;
		}
		void set_age(const int a) { age_ = a; }
		[[nodiscard]] int get_age() const { return age_; }
		void set_standard(const int s) { standard_ = s; }
		[[nodiscard]] int get_standard() const { return standard_; }
		void set_first_name(const std::string& f) { first_name_ = f; }
		[[nodiscard]] std::string get_first_name() const { return first_name_; }
		void set_last_name(const std::string& l) { last_name_ = l; }
		[[nodiscard]] std::string get_last_name() const { return last_name_; }
		[[nodiscard]] std::string to_string() const {
			std::ostringstream ss;
			ss << age_ << ',' + first_name_ + ',' + last_name_ + ',' << standard_;
			return ss.str();
		}
	};
}

using namespace class_ex;

int main() {
	int age, standard;
	std::string first_name, last_name;
	std::cin >> age >> first_name >> last_name >> standard;

	student st;
	st.set_age(age);
	st.set_standard(standard);
	st.set_first_name(first_name);
	st.set_last_name(last_name);
	std::cout << st.get_age() << '\n';
	std::cout << st.get_last_name() << ", " << st.get_first_name() << '\n';
	std::cout << st.get_standard() << '\n';
	std::cout << '\n';
	std::cout << st.to_string();
	return 0;
}
