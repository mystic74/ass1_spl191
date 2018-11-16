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
            if (firstWord == "open")
            {
                std::string str_number_of_tables = actionLine.substr(5,1);
                // Generate customers list
                std::vector<std::string> customerts_str = split(actionLine.substr(7),' ');
                CustomerFactory cF;
                for (auto str : customerts_str){
                    Customer* a = cF.generateCustomer(Customer::stringToEnum(str.substr(str.find(',') + 1)),
                                                      ++Restaurant::customer_id,
                                                      str.substr(0, str.find(',')));
                }



            }
            else if (firstWord == "order")
            {
            }
            else if (firstWord == "move")
            {

            }
            else if (firstWord == "close ")
            {

            }
            else if (firstWord == "status")
            {
            }
        }

        // So its "Close all, Menu, Log, Backup, Restore"
        else
        {

        }
    }
    return returnValue;
}

