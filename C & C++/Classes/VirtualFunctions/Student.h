#pragma once
#include "Person.h"

class student final
	: public person
{
    int marks_[6]{};
    int cur_id_;
public:
    static int id;
    student();
    void get_data() override;
    void put_data() override;
};