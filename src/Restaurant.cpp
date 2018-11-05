//
// Created by tom on 03/11/18.
//

#include "../include/Restaurant.h"
#include <cstdio>
#include <iostream>

Restaurant::Restaurant()
{
    throw std::runtime_error("error");
}

Restaurant::Restaurant(const std::string &configFilePath)
{
    throw std::runtime_error("error");
}


const std::vector<BaseAction*>& Restaurant::getActionsLog() const
{
    throw std::runtime_error("Not implemented");
    std::vector<BaseAction*> a =  new std::vector<BaseAction*>;

    return &a;
}

int Restaurant::getNumOfTables() const
{
    throw std::runtime_error("error");
    return 1;
}

Table* Restaurant::getTable(int ind)
{
    throw std::runtime_error("error");
    return std::nullptr;
}

std::vector<Dish>& Restaurant::getMenu()
{
    throw std::runtime_error("error");
    return std::nullptr;
}

void Restaurant::start()
{
    std::cout << "Resturant is now open!" << std::endl;

    std::cout << "Resturant is now open!" << std::endl;


}


