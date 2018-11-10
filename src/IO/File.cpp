/*
* Created by tom on 09/11/18.
**/

#include "File.h"


ConfigFileReader::ConfigFileReader(std::string file_name)
{
    this->mFile.open(file_name, std::ios_base::binary);

}

bool ConfigFileReader::is_open()
{
    return this->mFile.is_open();
}

