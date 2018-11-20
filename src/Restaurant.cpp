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
    this->delete_tables();
    this->delete_actionlog();
}



Restaurant:: Restaurant(const Restaurant& other)//copy constructor
{
    this->clear();
    this->open          = other.open;
    this->isOpen        = other.isOpen;
    this->nNumOfTables  = other.getNumOfTables();

    for (int i=0;i<NUM_OF_PARAMS;i++)
    {
        this->params_set[i] = other.params_set[i];
    }


    for (auto dish : other.menu)
    {
        this->menu.push_back(dish);
    }

    for (auto tableP : other.tables)
    {
        this->tables.push_back(new Table(*tableP));
    }

    for (auto action:other.actionsLog)
    {
        this->actionsLog.push_back(action->Clone());
    }


}


Restaurant & Restaurant::  operator=(const Restaurant& other) //copy assignment operator
{
    if (this != &other)
    {
        this->clear();

        this->open          = other.open;
        this->isOpen        = other.isOpen;
        this->nNumOfTables  = other.getNumOfTables();

        for (int i=0;i<NUM_OF_PARAMS;i++)
        {
            this->params_set[i] = other.params_set[i];
        }

        for (auto dish:other.menu)
        {
            this->menu.push_back(dish);
        }

        for (auto table: other.tables)
        {
            this->tables.push_back(table);
        }

        for (auto action: other.actionsLog)
        {
            this->actionsLog.push_back(action);
        }


    }
    return (*this);
}

Restaurant:: Restaurant(Restaurant&& other)//move constructor
{
    this->open=other.open;
    this->isOpen=other.isOpen;
    this->nNumOfTables=other.getNumOfTables();

    for (int i=0;i<NUM_OF_PARAMS;i++)
    {
        this->params_set[i]=other.params_set[i];
    }


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



    other.open=false;
    other.isOpen=false;
    other.nNumOfTables=0;

    other.delete_tables();
    other.delete_actionlog();
}


Restaurant& Restaurant:: operator=(Restaurant&& other)//move assignment operator
{
    if (this != &other)
    {
        this->open=other.open;
        this->isOpen=other.isOpen;
        this->nNumOfTables=other.getNumOfTables();

        for (int i=0;i<NUM_OF_PARAMS;i++)
        {
            this->params_set[i]=other.params_set[i];
        }

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

    other.open=false;
    other.isOpen=false;
    other.nNumOfTables=0;

    other.delete_tables();

    other.delete_actionlog();


    return (*this);
}



int Restaurant::customer_id;
Restaurant::Restaurant() :  open(false),
                            isOpen(false),
                            nNumOfTables(0),
                            params_set{false}
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
            else if (!params_set[AMOUNT_OF_TABLES])
            {
                this->nNumOfTables = std::stoi(cur_line);
                params_set[AMOUNT_OF_TABLES] = true;
            }
            else if (!params_set[TABLES_DESCRIPTION])
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

               // assert(this->tables.size() == ((unsigned int)this->nNumOfTables));
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

                delete currDish;
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
    for (unsigned int i=0; i < this->tables.size() ; i++)
    {
        if (tables[i] != nullptr)
        {
            delete this->tables[i];
            tables[i] = nullptr;
        }
    }
}

void Restaurant::delete_actionlog()
{
    for (unsigned int i=0; i < actionsLog.size(); i++)
    {
        if (actionsLog[i] != nullptr)
        {
            delete this->actionsLog[i];
            actionsLog[i] = nullptr;
        }
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
        (ind < 0)              ||
        (tables.size() < static_cast<unsigned int>(ind)))
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

    BaseAction* returnValue;
    LimitedFactory a;

    this->openRestaurant();


#if 1

    std::ifstream configFile("yuvalsCommands.txt", std::ios::binary);
    std::string cur_line;

    if (configFile) {
        while (getline(configFile, cur_line)) {
            returnValue = a.generateAction(cur_line);
            returnValue->act(*this);
            this->addActionLog(returnValue);

        }
    }
#endif
#if false
    // Fucking amazing mistake.
    while(this->isOpen)
    {
        std::getline(std::cin, strInput);


        returnValue = a.generateAction(strInput);
        returnValue->act(*this);
        this->addActionLog(returnValue);
    }
#endif

}

void Restaurant::openRestaurant()
{
    this->isOpen = true;
}

void Restaurant::closeRestaurant()
{
    this->isOpen = false;
}

bool Restaurant::addActionLog(BaseAction *aAction)
{
    this->actionsLog.push_back(aAction);
    return true;
}



