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

    return this->actionsLog;
}

int Restaurant::getNumOfTables() const
{
    throw std::runtime_error("error");
    return 1;
}

Table* Restaurant::getTable(int ind)
{
    throw std::runtime_error("error");
    return nullptr;
}

std::vector<Dish>& Restaurant::getMenu()
{
    throw std::runtime_error("error");
    return this->menu;
}

void Restaurant::start()
{
    std::cout << "Resturant is now open!" << std::endl;

    std::cout << "Resturant is now open!" << std::endl;


}


