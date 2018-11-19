#ifndef DISH_H_
#define DISH_H_

#include <string>

enum DishType{
    VEG, SPC, BVG, ALC
};

enum DishParams
{
    DISH_NAME,
    DISH_CATAGORY,
    DISH_PRICE,
    DISH_NUM_OF_PARAMS
};

class Dish{
public:
    Dish(int d_id, std::string d_name, int d_price, DishType d_type);

    Dish(Dish&& other)
    : id(other.id),
      name(other.name),
      price(other.price),
      type(other.type)

    {

    }


    // Copy constructor.
    Dish(const Dish& other)
            : id(other.id),
              name(other.name),
              price(other.price),
              type(other.type)
    {

    }

    int getId() const;
    std::string getName() const;
    int getPrice() const;
    DishType getType() const;
    ~Dish() {};
    static std::string enumToString(DishType  nNum);
    static DishType stringToEnum(std::string strName);
private:
	const int id;
    const std::string name;
    const int price;
    const DishType type;
    const static std::string strDishType[4];
};


#endif