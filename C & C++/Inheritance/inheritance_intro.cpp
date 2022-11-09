#include <iostream>

class triangle
{
public:
	static void triangle_def()
	{
		std::cout << "I am a triangle\n";
	}
};

class isosceles : public triangle
{
public:
	static void isosceles_def()
	{
		std::cout << "I am an isosceles triangle\n";
	}

	static void description()
	{
		std::cout << "In an isosceles triangle two sides are equal\n";
	}
};

int main()
{
	isosceles::isosceles_def();
	isosceles::description();
	isosceles::triangle_def();
	return 0;
}