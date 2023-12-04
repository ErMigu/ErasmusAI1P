#include <iostream>
#include <cstdlib>
#include "Argumentation.h"

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
//./erasmusAI 5 "arg(A1)" "arg(A2)" "arg(A3)" "arg(A4)" "att(A1,A2)" "att(A2,A1)" "att(A1,A4)"
//PONER SIEMPRE EL NUMERO 5, se hacen todos en cascada

int main(int argc, char* argv[]) {
    printArg(argc, argv);

    Argumentation myArg;
    myArg.readArg(argc, argv);
    myArg.printArg();

    std::cout<<"CF SETS: "<<std::endl;
    myArg.ej1(); //fill the ConflictFree
    myArg.printCfSets();
    std::cout<<std::endl;std::cout<<std::endl;

    std::cout<<"ADMISSIBLE SETS: "<<std::endl;
    myArg.ej2(); //fill the Admissible
    myArg.printAdmissibleSets();
    std::cout<<std::endl;std::cout<<std::endl;

    std::cout<<"STABLE EXTS: "<<std::endl;
    myArg.ej3(); //fill the Stable
    myArg.printStableSets();
    std::cout<<std::endl;std::cout<<std::endl;

    std::cout<<"PREFERRED EXTS: "<<std::endl;
    myArg.ej5(); //fill the Preferred
    myArg.printPreferredSets();
    std::cout<<std::endl;std::cout<<std::endl;

    return 0;
}
