#include "Person.h"

void person::get_data()
{
	std::cin >> name_;
	std::cin >> age_;
}

void person::put_data()
{
	std::cout << name_ << ' ';
	std::cout << age_ << ' ';
}