//
// Created by Pasarus on 09/12/2017.
//

#ifndef LOCALASSIGNMENTC_POD_H
#define LOCALASSIGNMENTC_POD_H


#include "Mammal.h"

class Pod {
private:
    std::vector<Mammal> pod;
public:
    void addToPod(Mammal);
    Mammal getFromPod(unsigned int);
    void fillPod(std::vector<Mammal>);
    std::vector<Mammal> getMammals();
    bool arePodsClose(Pod);
};

void createPods(std::vector<Pod>*, std::vector<Mammal>);
Pod combinePods(Pod *, Pod*);
void printMammalsAndPods(std::vector<Pod>, std::vector<Mammal>);

#endif //LOCALASSIGNMENTC_POD_H
