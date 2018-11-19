//
// Created by tom on 03/11/18.
//

#include "../include/Restaurant.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include "IO/File.h"
#include <include/ActionFactory.h>
#include "IO/MyString.h"
#include <assert.h>
#include <include/Restaurant.h>

using namespace std;


Restaurant::~Restaurant()//dtor
{
    for (auto table: tables)
    {
        delete table;
    }

    for (auto action: actionsLog)
    {
        delete action;
    }

}



Restaurant:: Restaurant(const Restaurant& other)//copy constructor
{
    this->open=other.open;
    this->isOpen=other.isOpen;
    this->getNumOfTables()=other.getNumOfTables();
    this->params_set=other.params_set;

    for (auto dish:other.menu)
    {
        this->menu.push_back(dish);
    }

    for (auto table: other.tables)
    {
        this->tables.push_back(table);
    }

    for (auto action:other.actionsLog)
    {
        this->actionsLog.push_back(action);
    }


}


Restaurant & Restaurant::  operator=(const Restaurant& other) //copy assignment operator
{
    if (this!=other)
    {
        this->open=other.open;
        this->isOpen=other.isOpen;
        this->getNumOfTables()=other.getNumOfTables();
        this->params_set=other.params_set;

        for (auto dish:other.menu)
        {
            this->menu.push_back(dish);
        }

        for (auto table: this->tables)
        {
            delete table;
        }

        for (auto table: other.tables)
        {
            this->tables.push_back(table);
        }

        for (auto action:this->actionsLog)
        {
            delete action;
        }

        for (auto action: other.actionsLog)
        {
            this->actionsLog.push_back(action);
        }


    }
    return (*this);
}

///TODO Rachel :finish move constructor and move assignment in Restaurant
Restaurant:: Restaurant(Restaurant&& other)//move constructor
{

}


Restaurant& Restaurant:: operator=(Restaurant&& other)//move assignment operator
{

}



int Restaurant::customer_id;
Restaurant::Restaurant()
{
    Restaurant::customer_id = 0;

}


Restaurant::Restaurant(const std::string &configFilePath) : Restaurant()
{
    std::ifstream configFile(configFilePath, std::ios::binary);
    std::string cur_line;

    if (configFile)
    {
        while(getline(configFile, cur_line))
        {
            if (cur_line.substr(0,1) == "#")
            {

                continue;
            }
            else if (params_set[AMOUNT_OF_TABLES] == false)
            {
                this->nNumOfTables = std::stoi(cur_line);
                params_set[AMOUNT_OF_TABLES] = true;
            }
            else if (params_set[TABLES_DESCRIPTION] == false)
            {
                std::vector<std::string> tablesVec = split(cur_line, ',');
                for (const auto strTab : tablesVec)
                {
                    // TODO TomR : Check for errors
                    // TODO TomR : And refactor the O in the name.
                    int num_0f_seats = std::stoi(strTab);

                    Table* currTable = new Table(num_0f_seats);
                    this->tables.insert(this->tables.begin(), currTable);
                }

                assert(this->tables.size() == ((unsigned int)this->nNumOfTables));
                params_set[TABLES_DESCRIPTION] = true;
            }
            else
            {
                std::vector<std::string> tablesVec = split(cur_line, ',');

                std::string strName = tablesVec[DISH_NAME];

                // TODO TomR : Check for int overflow in the menu.size()
                Dish* currDish = new Dish(static_cast<int>(this->menu.size()),
                                          strName,
                                          std::stoi(tablesVec[DISH_PRICE]),
                                          Dish::stringToEnum(tablesVec[DISH_CATAGORY]));

                this->menu.push_back(*currDish);



            }
        }
    }

}







void Restaurant:: clear()
{
    delete_tables();
    delete_actionlog();
}

void Restaurant::delete_tables()
{
    for (int i=0;i<this->tables.size();i++)
    {
        delete tables[i];
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
    // Set to unsigned, check <= or <, and check for negetive numbers
    if ((this->tables.empty()) ||
        (tables.size()<=ind))
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


    std::string strInput;

    std::getline(std::cin, strInput);

    BaseAction* returnValue;
    LimitedFactory a;


    returnValue = a.generateAction(strInput);
    this->openRestaurant();

    while(this-isOpen)
    {
        returnValue->act(*this);
        std::getline(std::cin, strInput);
        returnValue = a.generateAction(strInput);
    }

}

void Restaurant::openRestaurant()
{
    this->isOpen = true;
}

void Restaurant::closeRestaurant()
{
    this->isOpen = false;
}


