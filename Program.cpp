//
// Created by ens23mra on 2023-11-30.
//

#include "Program.h"

Program::Program(std::string name){
    this->name=name;
}


void Program::readArg(int argc, char* argv[]){
    std::vector<std::string> ruleT;

    for (int i = 2; i < argc; ++i) { //building rules
        std::string argument = argv[i];
        if (argument.find('.') != std::string::npos){ //finish rule
            ruleT.push_back(argument);
            rules.push_back(Rule(ruleT));
            ruleT.clear();
        }else{                           //building rule
            ruleT.push_back(argument);
        }
    }
    std::cout << "---DONEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE-" << std::endl;

    for (int i = 0; i < rules.size(); ++i) { //for each unknown rule
        std::vector<Atom> aux = rules[i].getAllAtoms();

        for (int j = 0; j < aux.size(); ++j) { //for each atom of that rule
            bool in=false;
            for(int k = 0; k < atoms.size(); ++k){ //look in my atoms
                if(atoms[k].getName()==aux[j].getName()){
                    in=true;
                    break;
                }
            }

            if(in==false){ //if is not there, I add it
                atoms.push_back(Atom(aux[j].getName(),true));
            }
        }
    }
    std::cout << "---DONEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE-" << std::endl;
}


void Program::printArg(){
    //NAME
    std::cout << "Name: " << name << std::endl;
    //ATOM
    std::cout << "Atoms:" << std::endl;
    for (Atom& atom : atoms) {
        std::cout << "   " << atom.getName() << std::endl;
    }
    //RULES
    std::cout << "Rules:" << std::endl;
    for (Rule& rule : rules) {
        rule.printAll();
    }
}


void Program::ej5() {

}