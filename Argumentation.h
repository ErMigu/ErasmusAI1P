//
// Created by ens23mra on 2023-11-30.
//

#ifndef ERASMUSAI1_ARGUMENTATION_H
#define ERASMUSAI1_ARGUMENTATION_H
#include <iostream>
#include <vector>
#include <cstring>
#include "stdexcept"

class Argumentation {
private:
    //Common
    std::vector<std::string> arg;
    std::vector<std::vector<std::string>> att;
    int typeOfProblem=0;

    //To work with
    std::vector<bool> used;
    std::vector<std::vector<std::string>> cfsets;
    std::vector<std::vector<std::string>> admissiblesets;

public:
    Argumentation();

    void readArg(int argc, char* argv[]);
    void printArg();

    void ej1();
    void isCF();
    void printcfSets();

    void ej2();
    void printadmissibleSets();

    void ej3();
    void ej4();

};


#endif //ERASMUSAI1_ARGUMENTATION_H
