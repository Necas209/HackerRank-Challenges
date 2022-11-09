#include <iostream>

class box
{
	long l_ = 0, b_ = 0, h_ = 0;
public:
	box() = default;
	box(int, int, int);
	box(const box&);
	[[nodiscard]] long get_length() const { return l_; }
	[[nodiscard]] long get_breadth() const { return b_; }
	[[nodiscard]] long get_height() const { return h_; }
	[[nodiscard]] long calculate_volume() const { return l_ * b_ * h_; }
	bool operator<(const box& b) const;
	friend std::ostream& operator<<(std::ostream& os, const box& b);
};

std::ostream& operator<<(std::ostream& os, const box& b)
{
	return os << b.l_ << ' ' << b.b_ << ' ' << b.h_;
}

bool box::operator<(const box& b) const
{
	return (l_ < b.l_ || (b_ < b.b_&& l_ == b.l_)
		|| (h_ < b.h_&& b_ == b.b_ && l_ == b.l_));
}

box::box(const int l, const int b, const int h)
{
	l_ = l;
	b_ = b;
	h_ = h;
}

box::box(const box& b)
{
	l_ = b.l_;
	b_ = b.b_;
	h_ = b.h_;
}


void check2()
{
	int n;
	std::cin >> n;
	box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		std::cin >> type;
		if (type == 1)
		{
			std::cout << temp << std::endl;
		}
		if (type == 2)
		{
			int l, b, h;
			std::cin >> l >> b >> h;
			const box new_box(l, b, h);
			temp = new_box;
			std::cout << temp << std::endl;
		}
		if (type == 3)
		{
			int l, b, h;
			std::cin >> l >> b >> h;
			if (box(l, b, h) < temp)
			{
				std::cout << "Lesser\n";
			}
			else
			{
				std::cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			std::cout << temp.calculate_volume() << std::endl;
		}
		if (type == 5)
		{
			const box& new_box(temp);
			std::cout << new_box << std::endl;
		}

	}
}

int main()
{
	check2();
}