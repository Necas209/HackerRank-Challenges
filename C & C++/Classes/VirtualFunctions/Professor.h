#pragma once
#include "Person.h"

class professor final
	: public person
{
    int cur_id_;
    int publications_;
public:
    static int id;
    professor();
    void get_data() override;
    void put_data() override;
};