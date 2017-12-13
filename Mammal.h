//
// Created by Pasarus on 07/12/2017.
//
#ifndef LOCALASSIGNMENTC_MAMMAL_H
#define LOCALASSIGNMENTC_MAMMAL_H

#include <vector>
#include <fstream>
#include "Location.h"

class Mammal {
private:
    char mammalType;
    Location location;
public:
    Mammal(char, double, double);
    char getMammalType();
    void setMammalType(char);
    Location getMammalLocation();
    void setMammalLocation(Location);
    Mammal copy();
};

void readInMammals(std::vector<Mammal>* mammals, std::ifstream &fs);
Mammal findAverageOfMammals(std::vector<Mammal> *mammals);
void findDuplicates(std::vector<Mammal>* mammals);
void printMammals(std::vector<Mammal>);

#endif //LOCALASSIGNMENTC_MAMMAL_H
