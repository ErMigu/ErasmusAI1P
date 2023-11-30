//
// Created by ens23mra on 2023-11-30.
//

#ifndef ERASMUSAI1_RULE_H
#define ERASMUSAI1_RULE_H
#include <vector>
#include "Atom.h"

class Rule {
private:
    Atom head;
    std::vector<Atom> body;

public:
    Rule(std::vector<std::string> ruleText);

    void addHead(Atom head);
    void addBody(Atom body);
    std::vector<Atom> getAllAtoms();

    void printAll();
};


#endif //ERASMUSAI1_RULE_H
