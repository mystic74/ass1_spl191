/*
* Created by tom on 09/11/18.
**/

#ifndef ASS1_FILE_H
#define ASS1_FILE_H

#include <iostream>
#include <string>
#include <fstream>

class ConfigFileReader
{
public:
    ConfigFileReader(std::string file_name);
    bool is_open();
private:
    std::ifstream mFile;
    std::string strFilePath;


};

#endif //ASS1_FILE_H
