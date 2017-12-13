//
// Created by Pasarus on 07/12/2017.
//

#include <algorithm>
#include <iostream>
#include "Mammal.h"

Mammal::Mammal(char type, double lat, double lon) : location(lat, lon){
    mammalType = type;
}

char Mammal::getMammalType() {
    return mammalType;
}

void Mammal::setMammalType(char newType) {
    mammalType = newType;
}

Location Mammal::getMammalLocation() {
    return location;
}

void Mammal::setMammalLocation(Location newLocation) {
    location = newLocation;
}

void readInMammals(std::vector<Mammal>* mammals, std::ifstream &fs){
    char tempType[2];
    double tempLong[2], tempLat[2];
    do{
        //Read in the value
        fs >> tempType[0] >> tempLat[0] >> tempLong[0];

        //If previous value is same as current value don't push to the vector
        //Could cause duplications to not be present but that won't matter because an average between two values that
        //are the same just leads to the same value, could cause issues with pods and calculating average locations
        //But duplications right next to each other shouldn't exist due to time differences anyways.
        if(!(tempLat[0] == tempLat[1] && tempLong[0] == tempLong[1] && tempType[0] == tempType[1])){
            mammals->push_back(*new Mammal(tempType[0], tempLat[0], tempLong[0]));
        }

        //Store variables for later checking
        tempType[1] = tempType[0];
        tempLat[1] = tempLat[0];
        tempLong[1] = tempLong[0];
    }while (!fs.eof());
}

Mammal findAverageOfMammals(std::vector<Mammal>* mammals){
    double avgLat = 0, avgLong = 0;
    for(unsigned int i = 0; i<mammals->size(); i++){
        avgLat += mammals->at(i).getMammalLocation().getLatitude();
        avgLong += mammals->at(i).getMammalLocation().getLongitude();
    }
    avgLat = avgLat / mammals->size();
    avgLong = avgLong / mammals->size();

    return *new Mammal(mammals->at(0).getMammalType(), avgLat, avgLong);
}

void findDuplicates(std::vector<Mammal>* mammals){
    std::vector<Mammal> average;
    bool foundDuplicate = false;
    int mammalsSize = mammals->size();
    for(unsigned int i = 0; i<mammalsSize; i++){
        for(unsigned int j = 0; j<mammalsSize; j++){
            if(i == j){
                continue;
            }
            Mammal mammal1 = mammals->at(i);
            Mammal mammal2 = mammals->at(j);
            double mammalDistance = mammal1.getMammalLocation().distance(mammal2.getMammalLocation());
            if(mammalDistance <= 0.02 && mammal1.getMammalType() == mammal2.getMammalType()){
                foundDuplicate = true;

                //Add to the average vector the duplicate values
                average.push_back(mammal1.copy());
                average.push_back(mammal2.copy());

                //Erase the values from the original array
                mammals->erase(mammals->begin() + j);
                mammalsSize = mammals->size();
            }
        }
        if(foundDuplicate){
            //Add the new mammal back in that was being found from the average vector
            mammals->erase(mammals->begin() + i);
            Mammal newMammal = findAverageOfMammals(&average);
            mammals->push_back(newMammal);
        }
        //Recalculate the size of the mammals
        mammalsSize = mammals->size();

        //Reset foundDuplicate
        foundDuplicate = false;
    }
}

Mammal Mammal::copy() {
    Mammal newMammal = *new Mammal(this->mammalType, this->location.getLatitude(), this->location.getLongitude());
    return newMammal;
}

void printMammals(std::vector<Mammal> mammals){
    std::cout << "Locations: " << std::endl;
    unsigned int mammalIterator;
    for(mammalIterator = 0; mammalIterator<mammals.size(); mammalIterator++){
        std::cout << mammals.at(mammalIterator).getMammalType() << " "
             << mammals.at(mammalIterator).getMammalLocation().getLatitude() << " "
             << mammals.at(mammalIterator).getMammalLocation().getLongitude() << std::endl;
    }
    std::cout << "\n";
}