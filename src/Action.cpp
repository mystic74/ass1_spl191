/*
* Created by tom on 08/11/18.
**/
#include <include/Action.h>
#include <include/Restaurant.h>
extern Restaurant* backup;

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

    std::cout << "ERROR : " + errorMsg << std::endl;
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


//
//OpenTable:: ~OpenTable()//dtor
//{
//    for (auto  customer:customers)
//    {
//        delete customer;
//    }
//}
//
//
//OpenTable:: OpenTable(const OpenTable& other) : tableId(other.tableId)//copy constructor
//{
//
//    for (auto customer: other.customers)
//    {
//        this->customers.push_back(customer);
//    }
//}
//
//
//OpenTable & OpenTable:: operator=(const OpenTable& other) //copy assignment operator
//{
//    if (this != &other)
//    {
//
//
//
//
//        for (auto customer: this->customers)
//        {
//            delete customer;
//        }
//
//        for (auto customer: other.customers)
//        {
//            this->customers.push_back(customer);
//        }
//    }
//    return (*this);
//
//}
//
/////TODO Rachel :finish move constructor and move assignment in Action-OpenTable
//OpenTable:: OpenTable(OpenTable&& other) //move constructor
//{
//
//}
//
//
//OpenTable & OpenTable:: operator=(OpenTable&& other)//move assignment operator
//{
//
//}






void OpenTable::act(Restaurant &restaurant)
{

    if (restaurant.getTable(tableId)== nullptr || restaurant.getTable(tableId)->isOpen()) {
        this->error("Table does not exist or already open");
    }
    else
    {
	    restaurant.getTable(tableId)->openTable();
        for (auto custumer : customers)
        {
	        restaurant.getTable(tableId)->addCustomer(custumer);
	    }

        this->complete();
    }
}

std::string OpenTable::toString() const
{
    std:: string stat;

    if (this->getStatus() == COMPLETED)
    {
        stat = this->getActionLine() +  " COMPLETED ";
    }
    else if (this->getStatus() == ERROR)
    {
        stat = this->getActionLine() + " ERROR " + this->getErrorMsg();
    }
    else
    {
        // Should we get here?
    }
    return stat;
}

BaseAction *OpenTable::Clone()
{
    return new OpenTable(*this);
}

OpenTable::~OpenTable()
{
    for (unsigned int nIndex = 0;
         nIndex < this->customers.size();
         nIndex++)
    {
        if (this->customers[nIndex] != nullptr)
        {
            delete customers[nIndex];
            customers[nIndex] = nullptr;
        }
    }
}

OpenTable::OpenTable(const OpenTable &other) :  BaseAction(other),
                                                tableId(other.tableId)
{
    for (unsigned int nIndex  = 0;
         nIndex < other.customers.size();
         nIndex++) {
        this->customers.push_back(other.customers[nIndex]->Clone());
    }
}



/// Generating Order
/// \param id The id for the table which takes orders
Order::Order(int id) :  BaseAction(),
                        tableId(id)
{

}

void Order::act(Restaurant &restaurant)
{
    if (restaurant.getTable(tableId) == nullptr || !(restaurant.getTable(tableId)->isOpen()))
    {
        this->error("Table does not exist or isn't open");
        return;
    }

    std:: vector<Customer*> table_customers= restaurant.getTable(tableId)->getCustomers();
    for (auto customer: table_customers )
    {
        std:: vector<int> currOrderList = customer->order(restaurant.getMenu());

        if (currOrderList.empty() == false) {
            // Generating OrderPair fro the last dish ordered, and the customer id, hopefully thats what they order

            for (auto currentOrder : currOrderList) {
                OrderPair currOrder = std::make_pair(customer->getId(),
                                                     *restaurant.getDish(currentOrder));
                restaurant.getTable(tableId)->addOrder(currOrder);
                std::cout << customer->getName() << " ordered "
                          << restaurant.getDish(currentOrder)->getName() << std::endl;
            }
        }
    }

    this->complete();

}

std::string Order::toString() const
{

        std::string stat;
        if (this->getStatus() == COMPLETED) {
            stat = this->getActionLine() + " COMPLETED";
        }
        else if (this->getStatus() == ERROR) {
            stat = this->getActionLine() + "ERROR: " + this->getErrorMsg();
        }
        else {
            stat = "Pending";
        }

        return stat;

}

BaseAction *Order::Clone()
{
    return new Order(*this);
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
    //origin or destination tables doesnt exist
    Table* tDstTable;
    Table* tSrcTable;
    tSrcTable = restaurant.getTable(srcTable);
    tDstTable = restaurant.getTable(dstTable);

    if (tSrcTable == nullptr ||
	    tDstTable == nullptr)
    {
	    this->error("cannot move customer");
    }
    //origin or destination tables closed
    else if (!tSrcTable->isOpen() ||
	         !tDstTable->isOpen())
    {
        this->error("cannot move customer");
    }

    //destination tables has no available seats
    // TODO TomR : <= or <?
    else if (static_cast<unsigned int>(tDstTable->getCapacity()) <= tDstTable->getCustomers().size())
         {
	        this->error("cannot move customer");
	 }
	 // All is well i guess?
    else
        {
            Customer* movingCust = tSrcTable->getCustomer(id);
            if (movingCust == nullptr)
            {
                this->error("cannot move customer");
            }

            // Whats happening here?
//            std:: vector<int> customerOrder=customerToMove->getOrderList();
  //          for (auto dish:customerOrder)
    //            cost=cost+getDishFromId(dish,restaurant.getMenu()).getPrice();

            tSrcTable->removeCustomer(id);
            tDstTable->addCustomer(movingCust);
            tDstTable->MoveOrders(*tSrcTable, id);

            this->complete();
        }

    ///need to move the bill and the customer to the dst table
}



std::string MoveCustomer::toString() const
{
    std:: string stat;

    if (this->getStatus() == COMPLETED)
    {
        stat = this->getActionLine() +  " COMPLETED ";
    }
    else if (this->getStatus() == ERROR)
    {
        stat = this->getActionLine() + " ERROR " + this->getErrorMsg();
    }
    else
    {
        // Should we get here?
    }
    return stat;
}

BaseAction *MoveCustomer::Clone()
{
    return new MoveCustomer(*this);
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
        this->complete();
    }
}

std::string Close::toString() const
{
    std:: string stat;
    if (this->getStatus()==COMPLETED) {
        stat = this->getActionLine() + "COMPLETED";
    }
    else if (this->getStatus()==ERROR)
    {
        stat = this->getActionLine() + "ERROR: " + this->getErrorMsg();
    }
    else
        stat="Pending";
    return stat;
}

BaseAction *Close::Clone()
{
    return new Close(*this);
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

    this->complete();
}

std::string PrintActionsLog::toString() const
{
    std:: string stat;

    if (this->getStatus() == COMPLETED)
    {
        stat = this->getActionLine() +  " COMPLETED ";
    }
    else if (this->getStatus() == ERROR)
    {
        stat = this->getActionLine() + " ERROR " + this->getErrorMsg();
    }
    else
    {
        // Should we get here?
    }
    return stat;
}

BaseAction *PrintActionsLog::Clone()
{
    return new PrintActionsLog(*this);
}

/**
 * Backups a restaurant
 * */
BackupRestaurant::BackupRestaurant() : BaseAction()
{

}



void BackupRestaurant::act(Restaurant &restaurant)
{
    if (backup != nullptr)
    {
        delete backup;
        backup = nullptr;
    }
    backup = new Restaurant(restaurant);
    this->complete();
}

std::string BackupRestaurant::toString() const
{
    std:: string stat;

    if (this->getStatus() == COMPLETED)
    {
        stat = this->getActionLine() +  " COMPLETED ";
    }
    else if (this->getStatus() == ERROR)
    {
        stat = this->getActionLine() + " ERROR " + this->getErrorMsg();
    }
    else
    {
        // Should we get here?
    }
    return stat;
}

BaseAction *BackupRestaurant::Clone()
{
    return new BackupRestaurant(*this);
}

/**
 * Restores a restuarant from backup
 * */
RestoreResturant::RestoreResturant() : BaseAction()
{

}

void RestoreResturant::act(Restaurant &restaurant)
{
    new (&restaurant) Restaurant(*backup);

    this->complete();
}

std::string RestoreResturant::toString() const
{
    std:: string stat;

    if (this->getStatus() == COMPLETED)
    {
        stat = this->getActionLine() +  " COMPLETED ";
    }
    else if (this->getStatus() == ERROR)
    {
        stat = this->getActionLine() + " ERROR " + this->getErrorMsg();
    }
    else
    {
        // Should we get here?
    }

    return stat;
}

BaseAction *RestoreResturant::Clone()
{
    return new RestoreResturant(*this);
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
    Table* currTable=restaurant.getTable(tableId);

    if (currTable->isOpen())
    {
        std:: cout<<"Table " + std::to_string(tableId) + " status: open" << std::endl;
        std:: vector <Customer*> customers= currTable->getCustomers();

        std:: cout<< "Customers:"<<std:: endl;
        for (auto customer: customers)
        {
            std:: cout <<customer->toString() << std:: endl;
        }

        std:: cout<< "Orders:"<< std:: endl;

        std:: vector<OrderPair> orders= currTable->getOrders();
        for (auto dish: orders)
        {
            std:: string dishName=dish.second.getName();
            int price= dish.second.getPrice();
            std:: cout <<dishName+" "+ std::to_string(price)+"NIS "+std::to_string(dish.first)<< std:: endl;
        }

        std:: cout<< "Current Bill: "+std:: to_string(currTable->getBill())+"NIS"<< std:: endl;
    }
    else
    {
        std:: cout<<"Table "+std::to_string(tableId)+" status: closed" << std::endl;
    }

    this->complete();

}

std::string PrintTableStatus::toString() const
{
    std:: string stat;

    if (this->getStatus() == COMPLETED)
    {
        stat = this->getActionLine() +  " COMPLETED ";
    }
    else if (this->getStatus() == ERROR)
    {
        stat = this->getActionLine() + " ERROR " + this->getErrorMsg();
    }
    else
    {
        // Should we get here?
    }
    return stat;
}

BaseAction *PrintTableStatus::Clone()
{
    return new PrintTableStatus(*this);
}

/// Close all tables
CloseAll::CloseAll() : BaseAction()
{

}

void CloseAll::act(Restaurant &restaurant)
{
    for (int i=0;i<restaurant.getNumOfTables();i++)
    {
        Table* currTable=restaurant.getTable(i);
        if (currTable->isOpen())
        {
            currTable->closeTable();
            std:: cout<<"Table " + std::to_string(i) + " was closed. Bill "+ std::to_string(currTable->getBill()) + "NIS"<< std:: endl;
        }
    }
    restaurant.delete_tables();
    restaurant.delete_actionlog();
    restaurant.closeRestaurant();

    // not so important though
    this->complete();
}

std::string CloseAll::toString() const
{
    return std::__cxx11::string();
}

BaseAction *CloseAll::Clone()
{
    return new CloseAll(*this);
}

/// Prints the menu
PrintMenu::PrintMenu() : BaseAction()
{

}

void PrintMenu::act(Restaurant &restaurant)
{
    std:: vector<Dish> menu=restaurant.getMenu();
    for (auto dish:menu)
    {
        std:: cout<< dish.getName()+" "+std:: to_string(dish.getType())+" "+std:: to_string(dish.getPrice())+"NIS"<<std:: endl;
    }
}

std::string PrintMenu::toString() const
{
    std:: string stat;
    if (this->getStatus()==COMPLETED) {
        stat = this->getActionLine() + "COMPLETED";
    }
    else if (this->getStatus()==ERROR)
    {
        stat = this->getActionLine() + "ERROR: " + this->getErrorMsg();
    }
    else
        stat="Pending";
    return stat;
}

BaseAction *PrintMenu::Clone()
{
    return new PrintMenu(*this);
}


Dish BaseAction:: getDishFromId(int DishId,std:: vector<Dish>menu)
{
    for (auto dish:menu)
        if (dish.getId()==DishId)
            return dish;
    throw std:: runtime_error("dish does not exist in the menu");
}

std::string BaseAction::getActionLine() const
{
    return this->actionLine;
}

BaseAction::BaseAction(const BaseAction &other) : actionLine(other.actionLine),
                                                  errorMsg(other.errorMsg),
                                                  status(other.status)
{

}

BaseAction::BaseAction(BaseAction &&other) :    actionLine(other.actionLine),
                                                errorMsg(other.errorMsg),
                                                status(other.status)
{
    other.actionLine    = "";
    other.errorMsg      = "";
    other.status        = PENDING;
}
