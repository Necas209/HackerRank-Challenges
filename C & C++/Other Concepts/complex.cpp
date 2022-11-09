#include <iostream>

class complex
{
	int a_{}, b_{};
public:
	complex() = default;

	complex(const int a, const int b) : a_(a), b_(b) {}

	void input(const std::string& s)
	{
		int v1 = 0;
		size_t i = 0;
		while (s[i] != '+')
		{
			v1 = v1 * 10 + s[i] - '0';
			i++;
		}
		while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
		{
			i++;
		}
		int v2 = 0;
		while (i < s.length())
		{
			v2 = v2 * 10 + s[i] - '0';
			i++;
		}
		a_ = v1;
		b_ = v2;
	}

	friend complex operator+(const complex& c1, const complex& c2);

	friend std::ostream& operator<<(std::ostream& os, const complex& c);
};

complex operator+(const complex& c1, const complex& c2)
{
	return { c1.a_ + c2.a_, c1.b_ + c2.b_ };
}

std::ostream& operator<<(std::ostream& os, const complex& c)
{
	return os << c.a_ << "+i" << c.b_;
}

int main()
{
	complex x, y;
	std::string s1, s2;
	std::cin >> s1 >> s2;
	x.input(s1);
	y.input(s2);
	const complex z = x + y;
	std::cout << z << std::endl;
}
