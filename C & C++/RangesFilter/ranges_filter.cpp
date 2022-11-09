#include <iostream>
#include <list>
#include <ranges>

using namespace std;

int main()
{
    list<int> lst;
    for (int i = 0; i <= 10; i++)
    {
        lst.push_back(i);
    }
    auto filter_func = [](int value) { return (value % 2) == 0; };
    auto filtered = ranges::filter_view(lst, filter_func);
    auto it = find(filtered.begin(), filtered.end(), [](int v) { return v == 4; });
    *it = 69;
    for (const auto& v : lst)
    {
        cout << v << ' ';
    }
    return 0;
}