/*
* Created by tom on 08/11/18.
*/

#include <include/Table.h>

Table::Table(int t_capacity):capacity(t_capacity)
                            , open(true)
{
    customersList(new std:: vector<Customer*>);
    orderList(new std:: vector<OrderPair>);

}

int Table::getCapacity() const
{
    return this->capacity;
}

void Table::addCustomer(Customer *customer)
{
    if (customersList.size()<capacity)
        this->customersList.push_back(customer);
}



void Table::removeCustomer(int id)
{
    for (int i=0;i<customersList.size();i++)
        if (customersList[i]->getId()==id)
            customersList.erase(customersList.begin()+i);
}


Customer *Table::getCustomer(int id)
{
    for (auto customer: customersList)
        if (customer->getId()==id)
            return customer;
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
    open=true;
}

void Table::closeTable()
{
    open=false;
}

int Table::getBill()
{
    int bill=0;
    for (auto order:orderList)
        bill=bill+order.second.getPrice();
    return bill;
}

bool Table::isOpen()
{
    return this->open;
}
