/*
* Created by tom on 08/11/18.
*/

#include <include/Customer.h>

#include "../include/Customer.h"

const std::string Customer::strCustomerType[4] = {"VEG","SPC","BVG","ALC"};

Customer::Customer(std::string c_name, int c_id) : name(c_name),
                                                   id(c_id)
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


const std::string Customer::enumToString(const CustomerType nNum)
{
    return Customer::strCustomerType[nNum];
}

const CustomerType Customer::stringToEnum(const std::string strName)
{
    for (int i = 0; i < sizeof(Customer::strCustomerType); ++i)
    {
        if (strName == Customer::strCustomerType[i])
        {
            return (static_cast<CustomerType >(i));
        }

    }

    return CUST_INVALID;
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
