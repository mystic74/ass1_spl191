/*
* Created by tom on 16/11/18.
**/

#include <include/CustomerFactory.h>

#include "include/CustomerFactory.h"

Customer* CustomerFactory::generateCustomer(CustomerType eType, int nID, std::string name)
{
    switch (eType)
    {
        case (CUST_ALC):
            return new AlchoholicCustomer(name, nID);
            break;
        case (CUST_CHP):
            return new CheapCustomer(name, nID);
            break;
        case (CUST_SPC):
            return new SpicyCustomer(name, nID);
            break;
        case (CUST_VEG):
            return new VegetarianCustomer(name, nID);
            break;
        // No validation, shouldn't happen.
        default:
            break;
    }
    return nullptr;
}
