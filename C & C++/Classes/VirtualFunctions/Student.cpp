#include "Student.h"
#include <numeric>

int student::id = 1;

student::student()
{
	cur_id_ = id++;
}

void student::get_data()
{
	person::get_data();
	for (int& i : marks_)
	{
		std::cin >> i;
	}
}

void student::put_data()
{
	person::put_data();
	std::cout << std::accumulate(marks_, marks_ + 6, 0) << ' ';
	std::cout << cur_id_ << std::endl;
}