/*
* Created by tom on 08/11/18.
*/

#include <include/Table.h>

Table::Table(int t_capacity)
{

}

int Table::getCapacity() const
{
    return 1;
}

void Table::addCustomer(Customer *customer)
{

}


///
/// \return
/// \param id
void Table::removeCustomer(int id)
{

}


Customer *Table::getCustomer(int id)
{
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
    return false;
}
