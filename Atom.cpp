//
// Created by ens23mra on 2023-11-30.
//

#include "Atom.h"

Atom::Atom(std::string name, bool posi){
    this->name=name;
    this->positive=posi;
}

Atom::Atom(){
    name="";
    positive=true;
}


std::string Atom::getName(){
    return name;
}


bool Atom::getPositive(){
    return positive;
}
