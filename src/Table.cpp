/*
* Created by tom on 08/11/18.
*/

#include <include/Table.h>

Table::Table(int t_capacity) : capacity(t_capacity)
{

}

int Table::getCapacity() const
{
    return this->capacity;
}

void Table::addCustomer(Customer *customer)
{
    // Should we really add to the beginning of the list?
    this->customersList.insert(this->customersList.begin(),customer);
}

void Table::removeCustomer(int id)
{
    for (int nIndex = 0; nIndex < this->customersList.size(); nIndex++)
    {
        if (this->customersList[nIndex]->getId() == id)
        {
            this->customersList.erase(this->customersList.begin() + nIndex);
        }

    }
}

Customer* Table::getCustomer(int id)
{
    for (int nIndex = 0; nIndex < this->customersList.size(); nIndex++)
    {
        if (this->customersList[nIndex]->getId() == id)
        {
            return this->customersList[nIndex];
        }
    }
    return nullptr;
}

std::vector<Customer *> &Table::getCustomers()
{
    return this->customersList;
}

std::vector<OrderPair> &Table::getOrders()
{
    return this->orderList;
}

void Table::order(const std::vector<Dish> &menu)
{

}

void Table::openTable()
{

}

void Table::closeTable()
{

}

int Table::getBill()
{
    return 0;
}

bool Table::isOpen()
{
    return this->open;
}
