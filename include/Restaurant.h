#ifndef RESTAURANT_H_
#define RESTAURANT_H_

enum FILE_PARAMS
{
    AMOUNT_OF_TABLES,
    TABLES_DESCRIPTION,
    MENU,
    NUM_OF_PARAMS
};

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
    int getNumOfTables() const;
    Table* getTable(int ind);
	const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Dish>& getMenu();

    static int customer_id;

private:
    bool open;
    std::vector<Table*> tables;
    std::vector<Dish> menu;
    std::vector<BaseAction*> actionsLog;

    int nNumOfTables = 0;
    bool params_set[NUM_OF_PARAMS];
};

#endif
