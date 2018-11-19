/*
* Created by tom on 08/11/18.
*/

#include <include/Table.h>

Table::Table(int t_capacity):capacity(t_capacity),
                             open(false)


Table:: ~Table()//dtor
{
    for (auto customer: customersList)
    {
        delete customer;
    }
}


Table:: Table(const Table& other)//copy constructor
{
    this->capacity=other.capacity;
    this->open=open;
    for (auto dish:other.orderList)
    {
        this->orderList.push_back(dish);
    }

    for (auto customer: other.customersList)
    {
        this->customersList.push_back(customer);
    }

}



Table & Table:: operator=(const Table& other) //copy assignment operator
{
    if (this!=other)
    {

        this->capacity=other.capacity;
        this->open=open;

        for (auto dish:other.orderList)
        {
            this->orderList.push_back(dish);
        }

        for (auto customer: this->customersList)
        {
            delete customer;
        }

        for (auto customer: other.customersList)
        {
            this->customersList.push_back(customer);
        }
    }
    return (*this);
}

///TODO Rachel :finish move constructor and move assignment in Table
Table:: Table(Table&& other)//move constructor
{

}

Table& Table:: operator=(Table&& other)//move assignment operator
{


}



Table::Table(int t_capacity):capacity(t_capacity)
                            , open(true)
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



bool Table::MoveOrders(Table &originTable, int nID)
{
    std::vector<OrderPair> newWorldOrder = {};
    for (unsigned int nIndex = 0; nIndex < originTable.orderList.size(); nIndex++)
    {
        if (originTable.orderList[nIndex].first == nID)
        {
            this->orderList.push_back(originTable.orderList[nIndex]);

        }
        else {
            newWorldOrder.push_back(originTable.orderList[nIndex]);
        }
    }


    while(originTable.orderList.empty() == false)
    {
        originTable.orderList.pop_back();
    }

    for (auto currItem : newWorldOrder)
    {
        originTable.orderList.push_back(currItem);
    }


}
