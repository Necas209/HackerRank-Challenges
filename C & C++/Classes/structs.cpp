#include <iostream>

typedef struct student_st
{
	int age{}, standard{};
	std::string first_name, last_name;
}student;

int main() {
	student st;
	std::cin >> st.age >> st.first_name >> st.last_name >> st.standard;
	std::cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

	return 0;
}