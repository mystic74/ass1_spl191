//
// Created by tom on 03/11/18.
//

#include "../include/Restaurant.h"
#include <cstdio>
#include <iostream>

Restaurant::Restaurant():
{
    throw std::runtime_error("error");
}

Restaurant::Restaurant(const std::string &configFilePath)
{
    throw std::runtime_error("error");
}


Restaurant::Restaurant(const Restaurant& a_Restaurant)
{
    for (int i=0; i<a_Restaurant.getNumOfTables(); i++)
    {
        tables[i]=a_Restaurant.getTable(i);
    }
    for (int i=0;i<a_Restaurant.getNumOfDishes();i++)
    {
        menu[i]=a_Restaurant.getDish(i);
    }

}

Restaurant:: ~Restaurant(){
delete_tables();
delete_menu();
delete_actionlog();

}



void Restaurant::delete_tables()
{
    for (int i=0;i<this->tables.size();i++)
    {
        delete tables[i];
    }

}


void Restaurant::delete_menu()
{
  for (int i=0;i<this->menu.size();i++)
  {
      delete menu[i];
  }
}

void Restaurant::delete_actionlog()
{
    for (int i=0; i<actionsLog.size();i++)
    {
        delete actionsLog[i];
    }

}



const std::vector<BaseAction*>& Restaurant::getActionsLog() const
{
    throw std::runtime_error("Not implemented");

    return this->actionsLog;
}

int Restaurant::getNumOfDishes() const
{
  return this->menu.size();
}

int Restaurant::getNumOfTables() const
{
    int size=this->tables .size();
    return size;
//    throw std::runtime_error("error");

}


Dish* Restautant::getDish(int ind)
{
    if (this->menu.empty())
    {
        return nullptr;
    }

    return menu[ind];
}

Table* Restaurant::getTable(int ind)
{
    if (this->tables.empty())
    {
        return nullptr;
    }
    return tables[ind];

}

std::vector<Dish>& Restaurant::getMenu()
{
    return this->menu;

}

void Restaurant::start()
{
    std::cout << "Resturant is now open!" << std::endl;



}


