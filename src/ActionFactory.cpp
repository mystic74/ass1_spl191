/*
* Created by tom on 12/11/18.
**/
#include <iostream>
#include <include/ActionFactory.h>
#include <src/IO/MyString.h>
#include <include/CustomerFactory.h>
#include <include/Restaurant.h>

BaseAction *LimitedFactory::generateAction(std::string actionLine)
{
    BaseAction* returnValue = nullptr;
    if (!actionLine.empty())
    {
        // Check if its "Open Order Move Close Status"
        if (actionLine.find(" ") != std::string::npos)
        {
            std::string firstWord = actionLine.substr(0, actionLine.find(" "));

            // What if its more then one digit?
            std::string str_number_of_tables = actionLine.substr(firstWord.length() + 1,1);

            if (firstWord == "open")
            {
                // Generate customers list
                std::vector<std::string> customerts_str = split(actionLine.substr(7 /* length of open + space + number + space*/),' ');

                CustomerFactory cF;
                std::vector<Customer*> cList;
                for (auto str : customerts_str){

                    Customer* tempC = cF.generateCustomer(Customer::stringToEnum(str.substr(str.find(',') + 1)),
                                                      ++Restaurant::customer_id,
                                                      str.substr(0, str.find(',')));

                    cList.insert(cList.begin(), tempC);
                    
                }

                returnValue = new OpenTable(std::stoi(str_number_of_tables), cList);

            }
            else if (firstWord == "order")
            {
                returnValue = new Order(std::stoi(str_number_of_tables));

            }
            else if (firstWord == "move")
            {
                // Should we somehow validate this? or just assume its right?
                int origin_table = std::stoi(str_number_of_tables);
                int dest_table = std::stoi(actionLine.substr(firstWord.length() + 3 /* +1 for first table, +2 for space, +3 for second one */, 1));
                int cust_id = std::stoi(actionLine.substr(firstWord.length() + 5 /* +3 for second table, +1 for space, +1 for id */, 1));
                returnValue = new MoveCustomer(origin_table, dest_table, cust_id);
            }
            else if (firstWord == "close ")
            {
                returnValue = new Close(std::stoi(str_number_of_tables));
            }
            else if (firstWord == "status")
            {
                returnValue = new PrintTableStatus(std::stoi(str_number_of_tables));
            }
        }

        // So its "Close all, Menu, Log, Backup, Restore"
        else {
            if (actionLine == "closeall") {
                returnValue = new CloseAll();
            }
            else if (actionLine == "menu") {
                returnValue = new PrintMenu();
            }
            else if (actionLine == "log") {
                returnValue = new PrintActionsLog();
            }
            else if (actionLine == "backup") {
                returnValue = new BackupRestaurant();

            }
            else if (actionLine == "restore") {
                returnValue = new RestoreResturant();

            }

            returnValue->setActionLine(actionLine);
        }
    }
    return returnValue;
}

