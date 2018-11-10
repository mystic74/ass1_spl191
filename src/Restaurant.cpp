//
// Created by tom on 03/11/18.
//

#include "../include/Restaurant.h"
#include "IO/File.h"
#include <cstdio>
#include <iostream>
#include <fstream>

#include "IO/MyString.h"
#include <cassert>

Restaurant::Restaurant()
{
    throw std::runtime_error("error");
}

Restaurant::Restaurant(const std::string &configFilePath) : params_set{false}
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

                assert(this->tables.size() == this->nNumOfTables);
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


const std::vector<BaseAction*>& Restaurant::getActionsLog() const
{

    return this->actionsLog;
}

int Restaurant::getNumOfTables() const
{
    this->tables.size();
}

Table* Restaurant::getTable(int ind)
{
   if ((ind > this->tables.size()) || (ind < 0))
   {
       return nullptr;
   }
   else
   {
       return this->tables[ind];
   }

}

std::vector<Dish>& Restaurant::getMenu()
{
    return this->menu;
}

void Restaurant::start()
{
    std::cout << "Resturant is now open!" << std::endl;
}



