cmake_minimum_required(VERSION 3.12)
project(ass1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "-g3")

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Werror")

include_directories(.)

add_executable(ass1
        include/Action.h
        include/Customer.h
        include/Dish.h
        include/Restaurant.h
        include/Table.h
        src/Customer.cpp
        src/Restaurant.cpp
        src/Dish.cpp
        src/Table.cpp
        src/Action.cpp
        Main.cpp
        src/IO/File.cpp
        src/IO/File.h
        src/IO/MyString.h src/ActionFactory.cpp include/ActionFactory.h src/CustomerFactory.cpp include/CustomerFactory.h)
