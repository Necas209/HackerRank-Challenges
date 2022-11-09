#include <iostream>
#include <vector>

class hotel_room
{
public:
	virtual ~hotel_room() = default;

	hotel_room(const int bedrooms, const int bathrooms)
		: bedrooms_(bedrooms), bathrooms_(bathrooms) {}

	[[nodiscard]] virtual int get_price() const
	{
		return 50 * bedrooms_ + 100 * bathrooms_;
	}

private:
	int bedrooms_;
	int bathrooms_;
};

class hotel_apartment final : public hotel_room
{
public:
	hotel_apartment(const int bedrooms, const int bathrooms)
		: hotel_room(bedrooms, bathrooms) {}

	[[nodiscard]] int get_price() const override
	{
		return hotel_room::get_price() + 100;
	}
};

int main()
{
	int n;
	std::cin >> n;
	std::vector<hotel_room*> rooms;
	for (int i = 0; i < n; ++i)
	{
		std::string room_type;
		int bedrooms;
		int bathrooms;
		std::cin >> room_type >> bedrooms >> bathrooms;
		if (room_type == "standard")
		{
			rooms.push_back(new hotel_room(bedrooms, bathrooms));
		}
		else
		{
			rooms.push_back(new hotel_apartment(bedrooms, bathrooms));
		}
	}

	int total_profit = 0;
	for (const auto& room : rooms)
	{
		total_profit += room->get_price();
	}
	std::cout << total_profit << std::endl;

	for (const auto room : rooms)
	{
		delete room;
	}
	return 0;
}