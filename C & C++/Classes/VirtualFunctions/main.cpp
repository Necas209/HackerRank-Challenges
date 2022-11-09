#include <iostream>
#include "Professor.h"
#include "Student.h"

int main()
{
	int n, val;
	std::cin >> n; // The number of objects that are going to be created
	const auto people = new person * [n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> val;
		if (val == 1)
			people[i] = new professor; // If val is 1 current object is of type Professor
		else
			people[i] = new student; // Else the current object is of type Student

		people[i]->get_data(); // Get the data from the user.
	}
	for (int i = 0; i < n; i++)
	{
		people[i]->put_data(); // Print the required output for each object.
	}
	return 0;
}
