/*
* Created by tom on 10/11/18.
**/
#ifndef MYSTRING_H

#define MYSTRING_H

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template<typename Out>
static void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

static std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
#endif