/*
* Created by tom on 08/11/18.
*/

#include <include/Customer.h>
#include <stdexcept>

#include "../include/Customer.h"


Customer::Customer(std::string c_name, int c_id) :  id(c_id)
                                                 ,  name(c_name)
                                                 ,  ordered(false)

{
    std:: vector<int> order_list;
}

std::string Customer::getName() const
{
    return this->name;
}

int Customer::getId() const
{
    return this->id;
}



VegetarianCustomer(std::string &c_name, int c_id) : Customer(c_name, c_id)
{

}

std::string VegetarianCustomer::toString() const
{
    return std::__cxx11::string();
}

std::vector<int> VegetarianCustomer::order(const std::vector<Dish> &menu)
{

    int small_id=-1;
    int large_price=-1;
    int food_id=-1;
    int bvg_id=-1;


    for (auto dish: menu)
    {
        if (dish.getType()==VEG)
            if(small_id==-1||dish.getId()<=small_id)
        {
            food_id=dish.getId();
            small_id=dish.getId();
        }
        if (dish.getType()==BVG&&dish.getPrice()>large_price)
        {
            bvg_id=dish.getId();
            large_price=dish.getPrice()
        }

    }

    //menu has no veg dish
    if(food_id==-1)
        return this->order_list;
    this->ordered=true;
    this->order_list.push_back(food_id);
    this->order_list.push_back(bvg_id);
    return this->order_list;

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
    if (this->ordered)
    {
        throw std:: invalid_argument("cheap customer can't order more then once");
    }
    int small_price=-1;
    int food_id=-1;
    for (auto dish:menu)
    {
        if (small_price==-1||dish.getPrice()<=small_price)
        {
            food_id=dish.getId();
            small_price=dish.getPrice();
        }
    }

    ordered=true;
    this->order_list.push_back(food_id);
    return this->order_list;
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
    int large_price=-1;
    int food_id=-1;
    int small_price=-1;

    if (this->ordered==false)
    {
        for (auto dish: menu)
        {
            if (dish.getPrice()>=large_price&&dish.getType()==SPC)
            {
                food_id=dish.getId();
                large_price=dish.getPrice();
            }
        }
    }
    else
    {
        for (auto dish: menu)
        {
            if(dish.getType()==BVG&&(small_price||dish.getPrice()<=small_price))
            {
                food_id=dish.getId();
                small_price=dish.getPrice()
            }
        }
    }
    this->ordered==true;
    this->order_list.push_back(food_id);
    return this->order_list;
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
