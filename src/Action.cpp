/*
* Created by tom on 08/11/18.
**/

#include <include/Action.h>
#include <include/Restaurant.h>
#include <Res>

BaseAction::BaseAction()
{

}

ActionStatus BaseAction::getStatus() const
{
    return this->status;
}

void BaseAction::complete()
{
    this->status=COMPLETED;
}

void BaseAction::error(std::string errorMsg)
{
    this->status=ERROR;
    this->errorMsg=errorMsg;
}

std::string BaseAction::getErrorMsg() const
{
    return this->errorMsg;
}


OpenTable::OpenTable(int id, std::vector<Customer *> &customersList) :  tableId(id),
                                                                        customers(customersList)
{

}

void OpenTable::act(Restaurant &restaurant)
{

    if (restaurant.getTable(tableId)== nullptr||restaurant.getTable(tableId)->isOpen())
        this->error("Table does not exist or already open");
    else
        restaurant.getTable(tableId)->openTable();
        for (auto custumer : customers)
            restaurant.getTable(tableId)->addCustomer(custumer);
}

std::string OpenTable::toString() const
{
    std:: string stat;
    if (this->getStatus()==COMPLETED)
        stat="COMPLETED";
    else
        if (this->getStatus()==ERROR)
            stat="ERROR: "+this->getErrorMsg();
    else
        stat="Pending";
    return stat;
}

Order::Order(int id) : tableId(id)
{

}

void Order::act(Restaurant &restaurant)
{
    if (restaurant.getTable(tableId)== nullptr||!(restaurant.getTable(tableId)->isOpen()))
        this->error("Table does not exist or isn't open");
    std:: vector<Customer*> table_customers= restaurant.getTable(tableId)->getCustomers();
    for (auto customer: table_customers )
        customer->order(restaurant.getMenu());
        //need to add a order list

}

std::string Order::toString() const
{
    {
        std:: string stat;
        if (this->getStatus()==COMPLETED)
            stat="COMPLETED";
        else
            if (this->getStatus()==ERROR)
                stat="ERROR: "+this->getErrorMsg();
        else
            stat="Pending";
        return stat;
    }

}

MoveCustomer::MoveCustomer(int src, int dst, int customerId) :  srcTable(src),
                                                                dstTable(dst),
                                                                id(customerId)
{

}


//need to finish
void MoveCustomer::act(Restaurant &restaurant)
{
    int cost=0;
    Customer* customerToMove= nullptr;
    //origin or destination tables doesnt exist
    if (restaurant.getTable(srcTable)== nullptr|restaurant.getTable(dstTable)== nullptr)
        this->error("cannot move customer");
    else
        //origin or destination tables closed
        if (!restaurant.getTable(srcTable)->isOpen()|!restaurant.getTable(dstTable)->isOpen());
    else
        //destination tables has no available seats
        if (restaurant.getTable(dstTable)->getCapacity()<=restaurant.getTable(dstTable)->getCustomers().size())
            this->error("cannot move customer");
    else
        {
            for (auto customer :restaurant.getTable(srcTable)->getCustomers())
                if (customer->getId()==id)
                    customerToMove=customer;
                if (customerToMove== nullptr)
                    this->error("cannot move customer");
            std:: vector<int> customerOrder=customerToMove->getOrderList();
            for (auto dish:customerOrder)
                cost=cost+getDishFromId(dish,restaurant.getMenu()).getPrice();

        }

    ///need to move the bill and the customer to the dst table
}



std::string MoveCustomer::toString() const
{
    return std::__cxx11::string();
}

Close::Close(int id) : tableId(id)
{

}

void Close::act(Restaurant &restaurant)
{

}

std::string Close::toString() const
{
    return std::__cxx11::string();
}



Dish BaseAction:: getDishFromId(int DishId,std:: vector<Dish>menu)
{
    for (auto dish:menu)
        if (dish.getId()==DishId)
            return dish;
    throw std:: runtime_error("dish does not exist in the menu");
}