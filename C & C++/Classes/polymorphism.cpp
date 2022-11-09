#include <iostream>
#include <list>
#include <map>

class lru_cache
{
	std::map<int, std::list<std::pair<int, int>>::iterator> mp_;
	size_t capacity_ = 0;
	std::list<std::pair<int, int>> cache_;
public:
	explicit lru_cache(const int capacity)
		: capacity_(capacity)
	{
	}
	void set(const int key, const int value)
	{
		if (mp_.contains(key))
		{
			mp_[key]->second = value;
			if (mp_[key] == cache_.begin())
			{
				cache_.push_front(*mp_[key]);
				cache_.erase(mp_[key]);
			}
		}
		else
		{
			cache_.emplace_front(key, value);
			if (cache_.size() > capacity_)
			{
				mp_.erase(cache_.back().first);
				cache_.pop_back();
			}
		}
		mp_[key] = cache_.begin();

	}
	int get(const int key)
	{
		if (mp_.contains(key))
		{
			return mp_[key]->second;
		}
		return -1;
	}
};

int main() {
	int n, capacity;
	std::cin >> n >> capacity;
	lru_cache l(capacity);
	for (int i = 0; i < n; i++) {
		std::string command;
		std::cin >> command;
		if (command == "get") {
			int key;
			std::cin >> key;
			std::cout << l.get(key) << std::endl;
		}
		else if (command == "set") {
			int key, value;
			std::cin >> key >> value;
			l.set(key, value);
		}
	}
	return 0;
}