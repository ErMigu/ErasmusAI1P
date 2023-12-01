//
// Created by ens23mra on 2023-11-30.
//

#ifndef ERASMUSAI1_ARGUMENTATION_H
#define ERASMUSAI1_ARGUMENTATION_H
#include <iostream>
#include <vector>
#include <cstring>
#include "stdexcept"
#include <algorithm>

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
    std::vector<std::vector<std::string>> stablesets;
    std::vector<std::vector<std::string>> preferredsets;

public:
    Argumentation();

    void readArg(int argc, char* argv[]);
    void printArg();

    void ej1();
    void isCF();
    void printCfSets();

    void ej2();
    void printAdmissibleSets();

    void ej3();
    void printStableSets();

    void ej4();
    void printPreferredSets();
};


#endif //ERASMUSAI1_ARGUMENTATION_H
