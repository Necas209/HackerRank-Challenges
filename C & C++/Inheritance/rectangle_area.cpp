#include <iostream>

using namespace std;
class rectangle
{
protected:
    int width_ = 0;
    int height_ = 0;
public:
    virtual ~rectangle() = default;

    void read_input()
    {
        std::cin >> width_ >> height_;
        std::cin.ignore();
    }

    virtual void display()
    {
        std::cout << width_ << ' ' << height_ << std::endl;
    }
};

class rectangle_area final : public rectangle
{
public:
	void display() override
	{
        std::cout << width_ * height_ << std::endl;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    rectangle_area r_area;
    /*
     * Read the width and height
     */
    r_area.read_input();
    /*
     * Print the width and height
     */
    r_area.rectangle::display();
    /*
     * Print the area
     */
    r_area.display();
    return 0;
}