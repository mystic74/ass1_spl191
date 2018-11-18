cmake_minimum_required(VERSION 3.12)
project(ass1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_RELEASE -Wall)

include_directories(.)

add_executable(ass1
        src/Customer.cpp
        src/Restaurant.cpp
        src/Action.cpp
        src/ActionFactory.cpp
        src/CustomerFactory.cpp
        src/Restaurant.cpp
        src/Table.cpp
        src/Dish.cpp
        Main.cpp
        )
