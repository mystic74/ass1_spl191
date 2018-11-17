/*
* Created by tom on 08/11/18.
**/
#include <include/Restaurant.h>
#include <include/Action.h>

BaseAction::BaseAction()
{
    this->status = PENDING;
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


OpenTable::OpenTable(int id, std::vector<Customer *> &customersList) :  BaseAction(),
                                                                        tableId(id),
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



/// Generating Order
/// \param id The id for the table which takes orders
Order::Order(int id) :  BaseAction(),
                        tableId(id)
{

}

void Order::act(Restaurant &restaurant)
{

}

std::string Order::toString() const
{
    return std::__cxx11::string();
}


/// Moves a customer from one table to the other
/// \param src The source table
/// \param dst The destination table
/// \param customerId The customer moving
MoveCustomer::MoveCustomer(int src, int dst, int customerId) :  BaseAction(),
                                                                srcTable(src),
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


/// Close a table
/// \param id The table that we close
Close::Close(int id) :  BaseAction(),
                        tableId(id)
{

}

void Close::act(Restaurant &restaurant)
{

}

std::string Close::toString() const
{
    return std::__cxx11::string();
}

/*
 * Prints the log for the entire table
 *
*/
PrintActionsLog::PrintActionsLog() : BaseAction()
{

}

void PrintActionsLog::act(Restaurant &restaurant)
{

}

std::string PrintActionsLog::toString() const
{
    return std::__cxx11::string();
}
/**
 * Backups a restaurant
 * */
BackupRestaurant::BackupRestaurant() : BaseAction()
{

}

void BackupRestaurant::act(Restaurant &restaurant)
{

}

std::string BackupRestaurant::toString() const
{
    return std::__cxx11::string();
}

/**
 * Restores a restuarant from backup
 * */
RestoreResturant::RestoreResturant() : BaseAction()
{

}

void RestoreResturant::act(Restaurant &restaurant)
{

}

std::string RestoreResturant::toString() const
{
    return std::__cxx11::string();
}

/**
 * Prints a current status for a table.
 * @param id The id for the table whos status will be printed
 * */
PrintTableStatus::PrintTableStatus(int id) :    BaseAction(),
                                                tableId(id)
{

}

void PrintTableStatus::act(Restaurant &restaurant)
{

}

std::string PrintTableStatus::toString() const
{
    return std::__cxx11::string();
}

/// Close all tables
CloseAll::CloseAll() : BaseAction()
{

}

void CloseAll::act(Restaurant &restaurant)
{

}

std::string CloseAll::toString() const
{
    return std::__cxx11::string();
}

/// Prints the menu
PrintMenu::PrintMenu() : BaseAction()
{

}

void PrintMenu::act(Restaurant &restaurant)
{

}

std::string PrintMenu::toString() const
{
    return std::__cxx11::string();
}
