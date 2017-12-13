//
// Created by Pasarus on 09/12/2017.
//

#include <iostream>
#include "Pod.h"
#define SAME_POD_DISTANCE 0.1

void Pod::addToPod(Mammal newAdd){
    pod.push_back(newAdd);
}

Mammal Pod::getFromPod(unsigned int positionInPod) {
    return pod.at(positionInPod);
}

void Pod::fillPod(std::vector<Mammal> mammalsToAdd){
    for(unsigned int i = 0; i<mammalsToAdd.size(); i++){
        Mammal nextMammal = mammalsToAdd.at(i);
        pod.push_back(nextMammal);
    }
}

std::vector<Mammal> Pod::getMammals() {
    return pod;
}

bool Pod::arePodsClose(Pod otherPod) {
    std::vector<Mammal> mammals1 = this->getMammals();
    std::vector<Mammal> mammals2 = otherPod.getMammals();
    //Iterate through the two mammal vectors
    for(unsigned int i = 0; i<mammals1.size(); i++){
        for(unsigned int j = 0; j<mammals2.size(); j++){

            //If mammals are of same type and are within SAME_POD_DISTANCE of eachother then return true else false
            if(mammals1.at(i).getMammalType() == mammals2.at(j).getMammalType() &&
                    mammals1.at(i).getMammalLocation().distance(mammals2.at(j).getMammalLocation()) <= SAME_POD_DISTANCE){
                return true;
            }
        }
    }
    return false;
}

Pod combinePods(Pod pod1, Pod pod2) {
    //Create new pod and fill it with values from Pod1, then add pod2 onto the end of newPod
    Pod newPod = *new Pod();
    newPod.fillPod(pod1.getMammals());
    for(unsigned int i = 0; i<pod2.getMammals().size(); i++){
        Mammal nextMammal = pod2.getMammals().at(i);
        newPod.addToPod(nextMammal);
    }
    return newPod;
}

void createPods(std::vector<Pod> *pods, std::vector<Mammal> mammals){
    //Create a pod for each mammal and put it into the pods vector
    for(unsigned int i = 0; i<mammals.size(); i++){
        Pod newPod = *new Pod();
        newPod.addToPod(mammals.at(i));
        pods->push_back(newPod);
    }

    //Iterate through pods
        //Iterate through the pod to compare to
            //If comparing the exact same position in vectors
                //continue;
            //if pod is near enough to other pod then
                //combine pod
            //else
                //continue;
        //Recalculate size of pod vector to change iterator max
    int podCount = pods->size();
    Pod newPod;
    bool podsCloseEnough = false;
    for(unsigned int i = 0; i<podCount; i++){
        for(unsigned int j = 0; j<podCount; j++){
            if(i == j){
                continue;
            }
            //if pods are close enough
            if(pods->at(i).arePodsClose(pods->at(j))){
                //Pods were close enough
                podsCloseEnough = true;

                //combine pods
                newPod = combinePods(pods->at(i), pods->at(j));

                //remove old pods
                pods->erase(pods->begin() + i);
                pods->erase(pods->begin() + j);

                //Take back the search parameters by one because there is one less pod in the vector
                i--;

                //Break out of this for loop and assume that the Pods will not need to combine again
                break;
            }
        }
        //If duplicate found, push back the new values
        if (podsCloseEnough){
            pods->push_back(newPod);
            //Recount the size of the pod vector
            podCount = pods->size();
        }
        podsCloseEnough = false;
    }
}

void printMammalsAndPods(std::vector<Pod> pods, std::vector<Mammal> mammals){
    //Print the mammals
    printMammals(mammals);

    //Print the pods and it's content
    unsigned int podIterator, podMammalIterator;
    for(podIterator = 0; podIterator<pods.size(); podIterator++){
        //Print out at the start of the pod the pod number
        std::cout << "Pod " << podIterator + 1 << ":" << std::endl;
        for(podMammalIterator = 0; podMammalIterator<pods.at(podIterator).getMammals().size(); podMammalIterator++){
            //Print out the contents of the pod
            std::cout << pods.at(podIterator).getMammals().at(podMammalIterator).getMammalType() << " "
                 << pods.at(podIterator).getMammals().at(podMammalIterator).getMammalLocation().getLatitude() << " "
                 << pods.at(podIterator).getMammals().at(podMammalIterator).getMammalLocation().getLongitude()
                      << std::endl;
        }
    }
}