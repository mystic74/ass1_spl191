/*
* Created by tom on 08/11/18.
**/

#include <include/Action.h>

BaseAction::BaseAction()
{

}

ActionStatus BaseAction::getStatus() const
{
    return this->status;
}

void BaseAction::complete()
{
    this->status = COMPLETED;
}

void BaseAction::error(std::string errorMsg)
{
    this->status = ERROR;

    // Does string use =, or should we use memcpy?
    // should we validate this somehow?
    this->errorMsg = errorMsg;
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

}

std::string OpenTable::toString() const
{
    return std::__cxx11::string();
}

Order::Order(int id) : tableId(id)
{

}

void Order::act(Restaurant &restaurant)
{

}

std::string Order::toString() const
{
    return std::__cxx11::string();
}

MoveCustomer::MoveCustomer(int src, int dst, int customerId) :  srcTable(src),
                                                                dstTable(dst),
                                                                id(customerId)
{

}

void MoveCustomer::act(Restaurant &restaurant)
{

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

PrintActionsLog::PrintActionsLog()
{

}

void PrintActionsLog::act(Restaurant &restaurant)
{

}

std::string PrintActionsLog::toString() const
{
    return std::__cxx11::string();
}

BackupRestaurant::BackupRestaurant()
{

}

void BackupRestaurant::act(Restaurant &restaurant)
{

}

std::string BackupRestaurant::toString() const
{
    return std::__cxx11::string();
}

RestoreResturant::RestoreResturant()
{

}

void RestoreResturant::act(Restaurant &restaurant)
{

}

std::string RestoreResturant::toString() const
{
    return std::__cxx11::string();
}
