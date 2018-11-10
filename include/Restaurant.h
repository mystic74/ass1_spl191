#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <vector>
#include <string>
#include "Dish.h"
#include "Table.h"
#include "Action.h"


class Restaurant{		
public:
	Restaurant();
    Restaurant(const std::string &configFilePath);
    void start();
	Restaurant(const Restaurant& a_Restaurant);
    ~Restaurant();
    int getNumOfTables() const;
	int getNumOfDishes() const;
	Table* getTable(int ind);
	Dish* getDish(int ind);
	const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Dish>& getMenu();
	void delete_tables();
	void delete_menu();
	void delete_actionlog();



private:
    bool open;
    std::vector<Table*> tables;
    std::vector<Dish> menu;
    std::vector<BaseAction*> actionsLog;
};

#endif