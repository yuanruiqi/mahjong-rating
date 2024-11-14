#include "maj.h"

void output(){
    for(auto player:players){
        std::string outputpath="./html/";
        outputpath+=player.name+".html";
        std::cerr<<outputpath<<'\n';
        std::ofstream cout(outputpath.c_str(),std::ios_base::out);
        cout<<player.name<<'\n';
    }
}