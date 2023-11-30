//
// Created by ens23mra on 2023-11-30.
//

#ifndef ERASMUSAI1_ATOM_H
#define ERASMUSAI1_ATOM_H
#include <iostream>


class Atom {
private:
    std::string name="";
    bool positive=true;

public:
    Atom(std::string name, bool posi);
    Atom();

    std::string getName();
    bool getPositive();

};


#endif //ERASMUSAI1_ATOM_H
