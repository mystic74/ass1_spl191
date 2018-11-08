/*
* Created by tom on 08/11/18.
*/

#include <include/Customer.h>

#include "../include/Customer.h"


Customer::Customer(std::string c_name, int c_id) :  id(c_id)
                                                 ,  name(c_name)
{

}

std::string Customer::getName() const
{
    return this->name;
}

int Customer::getId() const
{
    return this->id;
}



VegetarianCustomer(std::string &c_name, int c_id)
        : Customer(c_name, c_id)
{

}

std::string VegetarianCustomer::toString() const
{
    return std::__cxx11::string();
}

std::vector<int> VegetarianCustomer::order(const std::vector<Dish> &menu)
{
    return std::vector<int>();
}

VegetarianCustomer::VegetarianCustomer(std::string name, int id)
        : Customer(name, id)
{

}



CheapCustomer::CheapCustomer(std::string name, int id)
        : Customer(name, id)
{

}

std::vector<int> CheapCustomer::order(const std::vector<Dish> &menu)
{
    return std::vector<int>();
}

std::string CheapCustomer::toString() const
{
    return std::__cxx11::string();
}




SpicyCustomer::SpicyCustomer(std::string name, int id)
        : Customer(name, id)
{

}

std::vector<int> SpicyCustomer::order(const std::vector<Dish> &menu)
{
    return std::vector<int>();
}

std::string SpicyCustomer::toString() const
{
    return std::__cxx11::string();
}



AlchoholicCustomer::AlchoholicCustomer(std::string name, int id)
        : Customer(name, id)
{

}

std::vector<int> AlchoholicCustomer::order(const std::vector<Dish> &menu)
{
    return std::vector<int>();
}

std::string AlchoholicCustomer::toString() const
{
    return std::__cxx11::string();
}
