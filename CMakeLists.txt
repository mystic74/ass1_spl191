cmake_minimum_required(VERSION 3.12)
project(ass1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ass1
        src/Restaurant.cpp
        include/Action.h
        include/Customer.h
        include/Dish.h
        Main.cpp
        include/Restaurant.h
        include/Table.h)
