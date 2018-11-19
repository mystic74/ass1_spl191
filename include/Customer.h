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
//	~Customer();//dtor
//	Customer(const Customer& other);//copy constructor
//	Customer & operator=(const Customer& other); //copy assignment operator
//	Customer(Customer&& other); //move constructor
//	Customer&operator=(Customer&& other);//move assignment operator

    Customer(std::string c_name, int c_id);
    virtual std::vector<int> order(const std::vector<Dish> &menu)=0;
    virtual std::string toString() const = 0;
    std::string getName() const;
    int getId() const;
    const static std::string enumToString(const CustomerType  nNum);
    const static CustomerType stringToEnum(std::string strName);
    std:: vector<int>  getOrderList()const;
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
private:
};


class CheapCustomer : public Customer {
public:
	CheapCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
};


class SpicyCustomer : public Customer {
public:
	SpicyCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
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
private:
	std::vector<DishPrice> sortedPricesArray;
};


#endif