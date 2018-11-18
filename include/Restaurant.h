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
    Restaurant(const Restaurant& a_Restaurant);
    ~Restaurant();
    Restaurant & operator=(const Restaurant & a_Restaurant);
    
    int getNumOfTables() const;
    int getNumOfDishes() const;
    int getNumOfActionlog() const;
    Table* getTable(int ind);
    Dish* getDish(int ind);
    const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Dish>& getMenu();
    void copy(const Restaurant & a_Restaurant);
    void clear();
    void delete_tables();
	void delete_menu();
	void delete_actionlog();
    std:: vector <int> capacityVector(std:: string line);
    void createMenu(std:: string line,std:: vector<Dish> &menu,int id);

    static int customer_id;
    void openRestaurant();
    void closeRestaurant();
private:
    bool open;
    std::vector<Table*> tables;
    std::vector<Dish> menu;
    std::vector<BaseAction*> actionsLog;
    bool isOpen;
    int nNumOfTables = 0;
    bool params_set[NUM_OF_PARAMS];
};

#endif