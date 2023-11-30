//
// Created by ens23mra on 2023-11-30.
//
#include <iostream>
#include <vector>
#include "Atom.h"
#include "Rule.h"

#ifndef ERASMUSAI1_PROGRAM_H
#define ERASMUSAI1_PROGRAM_H


class Program {
private:
    std::string name="";
    std::vector<Atom> atoms;
    std::vector<Rule> rules;

public:
    Program(std::string name);

    void readArg(int argc, char* argv[]);
    void printArg();

    void ej5();

};


#endif //ERASMUSAI1_PROGRAM_H
