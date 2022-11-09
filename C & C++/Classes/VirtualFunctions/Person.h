#pragma once
#include <iostream>

class person
{
    std::string name_;
    int age_ = 0;
public:
    virtual ~person() = default;
    virtual void get_data();
    virtual void put_data();
};