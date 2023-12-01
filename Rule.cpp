//
// Created by ens23mra on 2023-11-30.
//

#include "Rule.h"

Rule::Rule(std::vector<std::string> ruleText){
    bool isBody=false;
    for (int i = 0; i < ruleText.size(); ++i) {
        if(isBody==false){ //head part
            if(ruleText[i]==":-"){ //to end the head
                isBody=true;
            }else{
                if(ruleText[i][0]=='-'){ //is negative
                    if(ruleText[i][ruleText[i].size()-1]=='.'){ //if it has point
                        head=Atom(ruleText[i].substr(1,ruleText[i].length()-2), false);
                    }else{
                        head=Atom(ruleText[i].substr(1,ruleText[i].length()-1), false);
                    }
                }else{ //is positive
                    if(ruleText[i][ruleText[i].size()-1]=='.'){ //if it has NO point
                        head=Atom(ruleText[i].substr(0,ruleText[i].length()-1), true);
                    }else{
                        head=Atom(ruleText[i].substr(0,ruleText[i].length()), true);
                    }
                }
            }
        }else{ //body part
            if(ruleText[i][0]=='-'){ //is negative
                if(ruleText[i][ruleText[i].size()-1]=='.'){ //if it has point
                    body.push_back(Atom(ruleText[i].substr(1,ruleText[i].length()-2), false));
                }else{
                    body.push_back(Atom(ruleText[i].substr(1,ruleText[i].length()-1), false));
                }
            }else{ //is positive
                if(ruleText[i][ruleText[i].size()-1]=='.'){ //if it has NO point
                    body.push_back(Atom(ruleText[i].substr(0,ruleText[i].length()-1), true));
                }else{
                    body.push_back(Atom(ruleText[i].substr(0,ruleText[i].length()), true));
                }
            }
        }
    }
}


void Rule::addHead(Atom head){
    this->head=head;
}


void Rule::addBody(Atom body){
    this->body.push_back(body);
}


std::vector<Atom> Rule::getAllAtoms(){
    std::vector<Atom> aux=body;
    aux.push_back(head);
    return std::vector<Atom>(aux);
}


void Rule::printAll() {
    std::cout << "   " << "Head:" << std::endl;

    if(head.getPositive()==true){
        std::cout << "   " <<  "   " <<head.getName() << "-Positive";
    }else{
        std::cout << "   " << "   " << head.getName() << "-Negative";
    }
    std::cout << std::endl;

    std::cout << "   " << "Body:" << std::endl;
    for (Atom& atom : body) {
        if(atom.getPositive()==true){
            std::cout << "   " << "   " << atom.getName() << "-Positive";
        }else{
            std::cout << "   " << "   " << atom.getName() << "-Negative";
        }
        std::cout << "  //  ";
    }
    std::cout << std::endl;std::cout << std::endl;
}
