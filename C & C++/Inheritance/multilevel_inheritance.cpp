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
};

class equilateral : public isosceles
{
public:
	static void equilateral_def()
    {
        std::cout << "I am an equilateral triangle\n";
    }
};

// Write your code here.

int main()
{
	equilateral::equilateral_def();
    equilateral::isosceles_def();
    equilateral::triangle_def();
    return 0;
}