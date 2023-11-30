//
// Created by ens23mra on 2023-11-30.
//

#include "Argumentation.h"


//arg(a)
//att(a,b)
/**READ THE ARGUMENTS AND BUILD THE ARGUMENTATION SET-UP**/
Argumentation::Argumentation() {}

void Argumentation::readArg(int argc, char* argv[]){
    typeOfProblem=stoi(std::string(argv[1]));
    for (int i = 2; i < argc; ++i) {
        std::string argu(argv[i]);
        if (argu.substr(0,3) == "arg") {
            arg.push_back(argu.substr(4, argu.length() - 5));
        } else {
            if (argu.substr(0,3) == "att") {
                int comaPos = static_cast<int>(argu.find(','));
                if(comaPos==4){
                    throw std::invalid_argument("INCORRECT ARGUMENTS");
                }

                std::vector<std::string> pair;
                pair.push_back(argu.substr(4,comaPos-4));
                pair.push_back(argu.substr(comaPos+1,argu.length() - pair[0].length() - 6));

                att.push_back(pair);
            } else {
                throw std::invalid_argument("INCORRECT ARGUMENTS");
            }
        }
    }
}


/**PRINT OF EVERYTHING**/
void Argumentation::printArg(){
    //ARG
    std::cout << "ArgLoaded (arg):" << std::endl;
    for (const std::string& argumento : arg) {
        std::cout << argumento << std::endl;
    }
    //ATT
    std::cout << "AttLoaded (att):" << std::endl;
    for (const std::vector<std::string>& ataque : att) {
        for (const std::string& argumento : ataque) {
            std::cout << argumento << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;std::cout << std::endl;
}


void Argumentation::ej1() {

}


void Argumentation::ej2() {

}


void Argumentation::ej3() {

}


void Argumentation::ej4() {

}