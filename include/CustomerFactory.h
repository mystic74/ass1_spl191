/*
* Created by tom on 16/11/18.
**/

#ifndef ASS1_CUSTOMERFACTORY_H
#define ASS1_CUSTOMERFACTORY_H
#include <include/Customer.h>

class CustomerFactory
{
    public:
    /// Generate a customer according to the type.
    /// \param eType The customer type, get it from StrToEnum.
    /// \param nID The running ID for the restaurant.
    /// \param name the clients name
    /// \return The instance of the customer
    Customer* generateCustomer(CustomerType eType, int nID, std::string name);
};


#endif //ASS1_CUSTOMERFACTORY_H
