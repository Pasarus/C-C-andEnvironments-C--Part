

#include <iostream>
#include <fstream>
#include "Location.h"
#include "Mammal.h"
#include "extraFuncs.h"
#include "Pod.h"

//Save needing to declare this repeatedly
using namespace std;

int main() {
    //Variable Declaration ---------------------------
    vector<Mammal> mammals;
    string mammalFileName;

    //Get the input file name ------------------------
    do{
        mammalFileName = "";
        cout << "Give the Mammals file name" << endl;
        cin >> mammalFileName;
        mammalFileName = "../" + mammalFileName;
    } while (!doesFileExist);

    //Open the file stream and assign it to a variable
    ifstream fs;
    fs.open(mammalFileName.c_str());

    //Read in the mammal data from the open file stream
    readInMammals(&mammals, fs);

    //Close the file stream
    fs.close();

    //Print mammals before duplicates are found
    cout << "The Initial Sightings:" << endl;
    cout << "\n";
    printMammals(mammals);
    cout << mammals.size() << " mammals" << endl;
    cout << "\n";

    //Find any duplicates and deal with them
    findDuplicates(&mammals);

    //Create the pods
    vector<Pod> pods;
    createPods(&pods, mammals);

    //Print the new mammals and new pods
    cout << "The True Sightings: " << endl;
    cout << "\n";
    printMammalsAndPods(pods, mammals);
    cout << "\n";
    cout << mammals.size() << " mammals" << endl;
    cout << pods.size() << " pods" << endl;

    return 0;
}
