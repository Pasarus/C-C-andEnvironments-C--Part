//
// Created by Pasarus on 09/12/2017.
//

#include <iostream>
#include "extraFuncs.h"

bool doesFileExist(const char *fileName){
    std::ifstream infile(fileName);
    return infile.good();
}