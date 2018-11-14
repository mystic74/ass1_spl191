//
// Created by tom on 03/11/18.
//

#include "../include/Restaurant.h"
#include <cstdio>
#include <iostream>

Restaurant::Restaurant():
{
    std:: vector <Table*> tables;
    std:: vector <Dish> manu;
    std::vector<BaseAction*> actionslog;
}

Restaurant::Restaurant(const std::string &configFilePath)
{
    throw std::runtime_error("error");
}


//copy constructor
Restaurant::Restaurant(const Restaurant& a_Restaurant)
{

    this->copy(a_Restaurant);
}

//destructor
Restaurant:: ~Restaurant(){
   clear();

}

Restaurant & Restaurant::operator=(const Restaurant & a_Restaurant)
{
    if (this==&a_Restaurant){
        return *this;
    }
    clear();
    this->copy(a_Restaurant);
    return *this;


}



void Restaurant:: copy(const Restaurant & a_Restaurant)
{

//    std:: vector <Table*> tables;
//    std:: vector <Dish> manu;
//    std::vector<BaseAction*> actionslog;
//
//    for (int i=0; i<a_Restaurant.getNumOfTables(); i++)
//    {
//        tables[i] = a_Restaurant.getTable(i);
//    }
//    for (int i=0;i<.a_Restaurnt.getNumOfDishes();i++)
//    {
//        menu[i]=a_Restaurant.getDish(i);
//    }
//    for (int i=0;i<.a_Restaurnt.getNumOfActionlog();i++)
//    {
//        actionsLog[i]=a_Restaurant.getActionsLog()[i];
//    }
}

void Restaurant:: clear()
{
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
    return this->actionsLog;

}

int Restaurant::getNumOfDishes() const
{
  return this->menu.size();
}

int Restaurant::getNumOfTables() const
{
    return this->tables .size();
}

int Restaurant:: getNumOfActionlog() const
{
    return this->actionsLog.size();

}


Dish* Restaurant::getDish(int ind)
{
    if (this->menu.empty())
    {
        return nullptr;
    }

    return &menu[ind];
}

Table* Restaurant::getTable(int ind)
{
    if (this->tables.empty()|tables.size()<=ind)
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


