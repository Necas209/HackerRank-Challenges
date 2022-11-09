#include <vector>
#include <iostream>
#include <numeric>

namespace classes_obj
{
	class student
	{
		int scores_[5]{};
	public:
		void input();
		int calculate_total_score();
	};
}

using namespace classes_obj;

void student::input()
{
	for (int& score : scores_)
	{
		std::cin >> score;
	}
}

int student::calculate_total_score()
{
	return std::accumulate(scores_, scores_ + 5, 0);
}

int main() {
	int n; // number of students
	std::cin >> n;
	const auto s = new student[n]; // an array of n students
	for (int i = 0; i < n; i++) {
		s[i].input();
	}
	// calculate kristen's score
	const int kristen_score = s[0].calculate_total_score();
	// determine how many students scored higher than kristen
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (s[i].calculate_total_score() > kristen_score) {
			count++;
		}
	}
	// print result
	std::cout << count;
	return 0;
}