//
// Created by ens23mra on 2023-11-30.
//
//arg(a)
//
//att(a,b) -- a ataca b

#include "Argumentation.h"

/**READ THE ARGUMENTS AND BUILD THE ARGUMENTATION SET-UP**/
Argumentation::Argumentation() {}


/**READER OF ARGUMENTS**/
void Argumentation::readArg(int argc, char* argv[]){
    typeOfProblem=stoi(std::string(argv[1]));
    for (int i = 2; i < argc; ++i) {
        std::string argu(argv[i]);
        if (argu.substr(0,3) == "arg") {
            arg.push_back(argu.substr(4, argu.length() - 5));
            used.push_back(false);
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


/**ALL "AF" BASED ON BACKTRACKING**/
void Argumentation::ej1() {
    for(int i=0; i<arg.size(); i++){
        if(used[i]==false){
            used[i]=true;
            isCF();
            ej1();
            used[i]=false;
        }
    }
}


/**AUXILIAR FOR EX1**/
void Argumentation::isCF(){
    std::vector<std::string> set;
    for(int i=0; i<used.size(); i++){ //making the vector
        if(used[i]==true) set.push_back(arg[i]);
    }

    int nrep;
    bool setFound=false;
    for(int i=0; i<cfsets.size(); i++){ //V of my solutions
        if(cfsets[i].size()==set.size()){ //if they have the same size
            nrep=0;
            bool notFound;
            for(int j=0; j<cfsets[i].size(); j++){ //V each element of X solution
                notFound= true;
                for(int k=0; k<set.size(); k++){ //find in the set
                    if(set[k]==cfsets[i][j]){ //si ese elemento esta me voy al siguiente
                        nrep++;
                        notFound=false;
                        break;
                    }
                }
                if(notFound==true) //si no esta cambio de conjunto
                    break;
            }
            if(nrep==set.size()){
                setFound=true;
                break;
            }
        }
    }


    if(setFound==false){ //check if is CF
        bool CF=true;
        for(int i=0; i<att.size(); i++){ //V ATAQUE
            int foundP=0;
            for(int j=0; j<att[i].size(); j++){ //MIRAMOS EL PAR
                for(int k=0; k<set.size(); k++){ //SI ESTA EN EL CONJUNTO
                    if(att[i][j]==set[k]){ //he encontrado una del par
                        foundP++;
                        break;
                    }
                }
                if(foundP==2){ //he encontrado el par
                    CF=false;
                    break;
                }
                if(foundP==0){ //no he encontrado la primera del par
                    break;
                }
            }
            if(foundP==2){ //he encontrado el par
                break;
            }
        }
        if(CF== true){
            if(cfsets.empty()==true){
                cfsets.push_back(std::vector<std::string>());
            }
            cfsets.push_back(set);
        }
    }
}


/**PRINT FOR EX1**/
void Argumentation::printcfSets(){
    for (const std::vector<std::string>& cfset : cfsets) {
        std::cout << "{ ";
        for (const std::string& argument : cfset) {
            std::cout << argument << " ";
        }
        std::cout << "}" << std::endl;
    }
}


/**ALL "ADMISSIBLE SETS"**/
void Argumentation::ej2() {
    bool cumple;
    for (int i = 0; i < cfsets.size(); ++i) { //V set
        cumple=true;
        for (int j = 0; j < cfsets[i].size(); ++j) { //V elemento del set
            bool atacado=false;
            std::string por;
            for (int k = 0; k < att.size(); ++k) { //V att
                if(att[k][1]==cfsets[i][j]){
                    atacado=true;
                    por=att[k][0];
                    break;
                }
            }
            if(atacado==true){ //si es atacado hay q ver si es defendido por alguien del conjunto
                bool defendido=false;
                for (int k = 0; k < cfsets[i].size(); ++k) { //V conjunto
                    for (int l = 0; l < att.size(); ++l) {
                        if(att[l][0]==cfsets[i][k] and att[l][1]==por){ //si lo encuentro
                            defendido=true;
                            break;
                        }
                    }
                    if(defendido==true){
                        break;
                    }
                }
                if(defendido==false){
                    cumple=false;
                    break;
                }
            }
        }
        if(cumple==true){
            admissiblesets.push_back(cfsets[i]);
        }
    }
}


/**PRINT FOR EX2**/
void Argumentation::printadmissibleSets(){
    for (const std::vector<std::string>& cfset : admissiblesets) {
        std::cout << "{ ";
        for (const std::string& argument : cfset) {
            std::cout << argument << " ";
        }
        std::cout << "}" << std::endl;
    }
}


void Argumentation::ej3() {

}


void Argumentation::ej4() {

}