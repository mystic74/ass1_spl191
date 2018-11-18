/*
* Created by tom on 08/11/18.
*/

#include <include/Dish.h>



const std::string Dish::strDishType[4] = {"VEG","SPC","BVG","ALC"};


Dish::Dish(int d_id, std::string d_name, int d_price, DishType d_type) : id(d_id),
                                                                         name(d_name),
                                                                         price(d_price),
                                                                         type(d_type)
{

}






int Dish::getId() const
{
    return this->id;
}

std::string Dish::getName() const
{
    return this->name;
}

int Dish::getPrice() const
{
    return this->price;
}

DishType Dish::getType() const
{
    return this->type;
}

std::string Dish::enumToString(DishType nNum)
{
    return Dish::strDishType[nNum];
}

DishType Dish::stringToEnum(std::string strName)
{
    for (unsigned int i = 0; i < sizeof(Dish::strDishType); ++i)
    {
        if (strName == Dish::strDishType[i])
        {
            return (static_cast<DishType>(i));
        }

    }

    // TODO TomR : How do i return an invalid type? stupid enum.
    return static_cast<DishType> (-1);
}
