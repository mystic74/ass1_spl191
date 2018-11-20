#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "Dish.h"



// Weird name, trying to avoid coupling for Dish and Customer
enum CustomerType{
	CUST_VEG,
    CUST_CHP,
	CUST_SPC,
	CUST_ALC,
	CUST_INVALID
};


class Customer{
public:
    	/// TODO :rule of 5?
    virtual	~Customer();//dtor
    Customer(const Customer& other);//copy constructor


// TODO TomR : If we don't use a virtual destructor, we can't delete a "Customer"  and expect him to arrive to the right dtor

    Customer(std::string c_name, int c_id);
    virtual std::vector<int> order(const std::vector<Dish> &menu)=0;
    virtual std::string toString() const = 0;
    std::string getName() const;
    int getId() const;
    const static std::string enumToString(const CustomerType  nNum);
    const static CustomerType stringToEnum(std::string strName);
    std:: vector<int>  getOrderList()const;

    virtual Customer* Clone() = 0;
private:
    const std::string name;
    const int id;
    const static std::string strCustomerType[4];
protected:
    int ordered;
    std:: vector<int> order_list;
};


class VegetarianCustomer : public Customer {
public:
	VegetarianCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    Customer* Clone();
private:
};


class CheapCustomer : public Customer {
public:
	CheapCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    Customer* Clone();
private:
};


class SpicyCustomer : public Customer {
public:
	SpicyCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    Customer* Clone();
private:
};


class AlchoholicCustomer : public Customer {


struct DishPrice
{
	int price;
	int id;

	// This might be better.
	 bool operator<(DishPrice const &r) const {
		if (this->price != r.price)
			return this->price < r.price;
		else
			return this->id < r.id;
	 }
};

public:
	AlchoholicCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    Customer* Clone();
private:
	std::vector<DishPrice> sortedPricesArray;
};


#endif