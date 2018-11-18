/*
* Created by tom on 08/11/18.
**/
#include <include/Action.h>
#include <include/Restaurant.h>

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
    this->errorMsg = errorMsg;
}

std::string BaseAction::getErrorMsg() const
{
    return this->errorMsg;
}

bool BaseAction::setActionLine(std::string stdLine)
{
    this->actionLine = stdLine;
    return true;
}

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList) :  BaseAction(),
                                                                        tableId(id),
                                                                        customers(customersList)
{

}

void OpenTable::act(Restaurant &restaurant)
{

    if (restaurant.getTable(tableId)== nullptr||restaurant.getTable(tableId)->isOpen())
        this->error("Table does not exist or already open");
    else
    {
	restaurant.getTable(tableId)->openTable();
        for (auto custumer : customers)
        {
	    restaurant.getTable(tableId)->addCustomer(custumer);
	}
    }
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



/// Generating Order
/// \param id The id for the table which takes orders
Order::Order(int id) :  BaseAction(),
                        tableId(id)
{

}

void Order::act(Restaurant &restaurant)
{
    if (restaurant.getTable(tableId)== nullptr||!(restaurant.getTable(tableId)->isOpen()))
        this->error("Table does not exist or isn't open");
    std:: vector<Customer*> table_customers= restaurant.getTable(tableId)->getCustomers();
    for (auto customer: table_customers )
    {
        customer->order(restaurant.getMenu());
        //need to add a order list
    }
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


// TODO RachelBr : need to finish
void MoveCustomer::act(Restaurant &restaurant)
{
    int cost=0;
    Customer* customerToMove= nullptr;
    //origin or destination tables doesnt exist
    if (restaurant.getTable(srcTable)== nullptr || 
	restaurant.getTable(dstTable)== nullptr)
    {
	this->error("cannot move customer"); 
    }
    //origin or destination tables closed
    else if (!restaurant.getTable(srcTable)->isOpen() || 
	    !restaurant.getTable(dstTable)->isOpen());
    // TODO Add content?

    //destination tables has no available seats
    else if (restaurant.getTable(dstTable)->getCapacity()<=restaurant.getTable(dstTable)->getCustomers().size())
         {
	   this->error("cannot move customer");
	 }
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


/// Close a table
/// \param id The table that we close
Close::Close(int id) :  BaseAction(),
                        tableId(id)
{

}

void Close::act(Restaurant &restaurant)
{

    // TODO TomR : Validate everything?
    if (restaurant.getTable(this->tableId)->isOpen() == false)
    {
        this->error("Table is not opened, failed to close table");
    }
    else
    {
        restaurant.getTable(this->tableId)->closeTable();
    }
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
    for (auto currLog : restaurant.getActionsLog())
    {
        // TODO TomR : Print them?

        // Should work i guess?
        std::cout << currLog->toString() << std::endl; 
    }
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


Dish BaseAction:: getDishFromId(int DishId,std:: vector<Dish>menu)
{
    for (auto dish:menu)
        if (dish.getId()==DishId)
            return dish;
    throw std:: runtime_error("dish does not exist in the menu");
}