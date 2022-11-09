#include "Professor.h"

int professor::id = 1;

professor::professor() 
{
    cur_id_ = id++;
    publications_ = 0;
}

void professor::get_data()
{
    person::get_data();
    std::cin >> publications_;
}

void professor::put_data()
{
    person::put_data();
    std::cout << publications_ << ' ';
    std::cout << cur_id_ << std::endl;
}