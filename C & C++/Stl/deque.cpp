#include <algorithm>
#include <iostream>

void print_k_max(int arr[], const int n, const int k)
{
    auto i_max = std::max_element(arr, arr + k);
    for (int i = 0; i < n - k + 1; i++)
    {
        if (arr[i + k - 1] >= *i_max)
        {
            i_max = arr + i + k - 1;
        }
        else if(i_max < arr + i)
        {
            i_max = std::max_element(arr + i, arr + i + k);
        }
        std::cout << *i_max << ' ';
    }
    std::cout << std::endl;
}

int main() {

	int t;
	std::cin >> t;
	while (t-- > 0)
	{
		int n, k;
		std::cin >> n >> k;
		const auto arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> arr[i];
		}
		print_k_max(arr, n, k);
	}
	return 0;
}
