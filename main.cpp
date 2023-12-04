#include <iostream>
#include <cstdlib>
#include "Argumentation.h"
#include "Program.h"

/**ARG PRINT**/
void printArg(int argc, char* argv[]){
    std::cout << std::endl;
    std::cout << "Número de argumentos: " << argc << std::endl;
    for (int i = 0; i < argc; ++i){
        std::cout << "A" << i << ":" << argv[i] << "  //  ";
    }
    std::cout << std::endl << std::endl << std::endl;
}


/**USING RULES**/
//-> Argumentation sintax -> NUMERODEPROBLEMA arg(a) arg(b) arg(..) att(a,b) att(b,...)
//./erasmusAI 1 "arg(A1)" "arg(A2)" "arg(A3)" "arg(A4)" "att(A1,A2)" "att(A2,A1)" "att(A1,A4)"

//-> Semantics sintax -> 5 x :- -y. y. z :- x
//./erasmusAI 5 a :- -b. b. c :- -a.


int main(int argc, char* argv[]) {
    printArg(argc, argv);

    Argumentation myArg;
    Program myProgram("P1");

    if(stoi(std::string(argv[1]))>5 or stoi(std::string(argv[1]))<1){
        throw std::invalid_argument("nie");
    }else{
        if(stoi(std::string(argv[1]))==5){
            myProgram.readArg(argc, argv);
            myProgram.printArg();
        }else{
            myArg.readArg(argc, argv);
            myArg.printArg();
        }
    }

    myProgram.ej5();

    return 0;
}
