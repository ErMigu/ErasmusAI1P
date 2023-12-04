#include <iostream>
#include <cstdlib>
#include "Argumentation.h"
#include <chrono>

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
//./erasmusAI "arg(a)" "arg(b)" "arg(c)" "arg(d)" "arg(e)" "att(a,b)" "att(b,c)" "att(c,a)" "att(d,e)"
//./erasmusAI "arg(a)" "arg(b)" "arg(c)" "arg(d)" "arg(e)" "arg(f)" "arg(g)" "arg(h)" "arg(i)" "arg(j)" \
"att(a,b)" "att(b,c)" "att(c,d)" "att(d,e)" "att(e,f)" \
"att(f,g)" "att(g,h)" "att(h,i)" "att(i,j)" "att(j,a)" \
"att(a,d)" "att(c,e)" "att(e,g)" "att(g,i)" "att(b,h)" \
"att(d,f)" "att(f,h)" "att(h,j)" "att(j,b)" "att(b,e)"


int main(int argc, char* argv[]) {
    printArg(argc, argv);

    Argumentation myArg;
    myArg.readArg(argc, argv);
    //myArg.printArg();

    auto start_time = std::chrono::high_resolution_clock::now();
    std::cout<<"CF SETS: "<<std::endl;
    myArg.ej1(); //fill the ConflictFree
    //myArg.printCfSets();
    std::cout<<std::endl;std::cout<<std::endl;

    std::cout<<"ADMISSIBLE SETS: "<<std::endl;
    myArg.ej2(); //fill the Admissible
    //myArg.printAdmissibleSets();
    std::cout<<std::endl;std::cout<<std::endl;

    std::cout<<"STABLE EXTS: "<<std::endl;
    myArg.ej3(); //fill the Stable
    myArg.printStableSets();
    std::cout<<std::endl;std::cout<<std::endl;

    std::cout<<"PREFERRED EXTS: "<<std::endl;
    myArg.ej5(); //fill the Preferred
    auto end_time = std::chrono::high_resolution_clock::now();

    myArg.printPreferredSets();
    std::cout<<std::endl;std::cout<<std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time: " << duration.count() << " ms" << std::endl;

    return 0;
}
