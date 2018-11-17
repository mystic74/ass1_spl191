//
// Created by tom on 03/11/18.
//

#include "../include/Restaurant.h"
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;


Restaurant::Restaurant():
{
    tables(new vector <Table*>);
    manu(new vector(Dish>));
    actionslog(new vector<BaseAction> actionsLog);
}

Restaurant::Restaurant(const std::string &configFilePath)
{

    ifstream myfile;
    string line;
    myfile.open(configFilePath+".txt");
    int lineNumber=0;
    string prevLine;
    int dishNumber=0;


    while (getline(myfile,line))
    {
        if (line.at(0)=='#')
        {
            prevLine=line;
            lineNumber++;
        }

        else
        {
            if(prevLine=="#number of tables")
                tables (new vector<Table*>(line.at(0)));
            else
                //creates the tables vector
                if (prevLine=="#tables description")
                {
                    vector <int> TablesCapacity =capacityVector(line);
                    for (int i=0;i<tables.size();i++)
                    {
                        Table* table=new Table(TablesCapacity[i]);
                        tables.insert(table);
                    }
                }
            else
                //creates the menu
                {
                    menu (new vector <Dish>);
                    createMenu(line,menu&,dishNumber);
                    dishNumber++;

                }

        }


    }

}

//helper function: creates dish from menu line in the file
void Restaurant::createMenu(string line, vector<Dish> &menu,int id)
{

    string name;
    int price;
    DishType type;
    string word="";
    int wordNumber=1;
    for (int i=0;i<line.size();i++)
        if (line[i]!=','&line[i]!=' ')
            word=word+line[i];
        else
        {
            if (wordNumber==1)
                name=word;
            else
            {
                if (wordNumber==2)
                    type=word;
            }
            else
            {
                price=int(word);
            }
            word="";
            wordNumber++;
        }
    menu.insert(new Dish (id,name,price,type));
}


//helper function: creates vector with capacity for each table
vector <int> Restaurant::capacityVector(string line)
{
    vector <int> TablesCapacity;
    for (int i=0;i<line.size();i++)
        if (line.at(i)!=','&&line.at(i)!=' ')
            TablesCapacity.push_back(line.at(i));
    return TablesCapacity;
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


