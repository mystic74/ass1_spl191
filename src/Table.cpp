/*
* Created by tom on 08/11/18.
*/

#include <include/Table.h>

Table::Table(int t_capacity):capacity(t_capacity),
                             open(false)
{


}

int Table::getCapacity() const
{
    return this->capacity;
}

void Table::addCustomer(Customer *customer)
{
    if (customersList.size()<capacity) {
        this->customersList.insert(this->customersList.begin(), customer);
    }
}



void Table::removeCustomer(int id)
{
    for (unsigned int nIndex = 0; nIndex < this->customersList.size(); nIndex++)
    {
        if (this->customersList[nIndex]->getId() == id)
        {
            this->customersList.erase(this->customersList.begin() + nIndex);
        }

    }
}

Customer* Table::getCustomer(int id)
{
    for (unsigned int nIndex = 0; nIndex < this->customersList.size(); nIndex++)
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
    this->open = true;
}

void Table::closeTable()
{
    this->open = false;
}

int Table::getBill()
{
    int bill = 0;
    for (auto order:orderList)
    {
        bill=bill+order.second.getPrice();
    }
    return bill;
}

bool Table::addOrder(OrderPair opOrder)
{
    this->orderList.push_back(opOrder);
    return true;
}

bool Table::isOpen()
{
    return this->open;
}
