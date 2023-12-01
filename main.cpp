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

    switch (std::atoi(argv[1])) {
        case 1: //SON LOS QUE NO SE ATACAN ENTRE ESE CONJUNTO
            std::cout << "Program 1: Given an argumentation framework (AF), Program 1 computes the conflict-free sets of AF." << std::endl;
            myArg.ej1();
            myArg.printcfSets();
            break;

        case 2:
            std::cout << "Program 2: Given an argumentation framework (AF), Program 2 computes the admissible sets of AF." << std::endl;
            myArg.ej1();
            myArg.ej2();
            myArg.printadmissibleSets();
            break;

        case 3:
            std::cout << "Program 3: Given an argumentation framework (AF), Program 3 computes the stable extensions of AF." << std::endl;
            myArg.ej3();
            break;

        case 4:
            std::cout << "Program 4: Given an argumentation framework (AF), Program 4 computes the preferred extensions of AF." << std::endl;
            myArg.ej4();
            break;

        case 5:
            std::cout << "Program 5: Implement a program/solver that computes the preferred semantics using your favorite programming language." << std::endl;
            myProgram.ej5();
            break;

        default:
            std::cout << "El primer argumento no es 1, 2, 3, 4 ni 5." << std::endl;
            break;


    }
    return 0;
}
