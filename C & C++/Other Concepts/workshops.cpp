#include <algorithm>
#include <iostream>
#include <vector>

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

typedef struct workshop
{
	int start_time;
	int end_time;
	int duration;
}workshop;

typedef struct available_workshops
{
	std::vector<workshop> workshops;

	explicit available_workshops(const int n)
	{
		workshops = std::vector<workshop>(n);
	}
}available_workshops;

available_workshops* initialize(int start_time[], int duration[], const int n)
{
	const auto av_ws = new ::available_workshops(n);
	for (int i = 0; i < n; i++)
	{
		av_ws->workshops[i] = { start_time[i],
			start_time[i] + duration[i],duration[i] };
	}
	std::ranges::sort(av_ws->workshops, [](const auto& w1, const auto& w2)
		{ return w1.end_time < w2.end_time; });
	return av_ws;
}

int calculate_max_workshops(const available_workshops* ptr)
{
	int curr_end_time = 0;
	int count = 0;
	for (const auto& [start_time, end_time, duration] : ptr->workshops)
		if (start_time >= curr_end_time)
		{
			curr_end_time = end_time;
			count += 1;
		}
	return count;
}

int main() {
	int n; // number of workshops
	std::cin >> n;
	// create arrays of unknown size n
	const auto start_time = new int[n];
	const auto duration = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> duration[i];
	}
	const auto ptr = initialize(start_time, duration, n);
	std::cout << calculate_max_workshops(ptr) << std::endl;
	return 0;
}