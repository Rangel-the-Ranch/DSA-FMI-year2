#include"SkipList.hpp"

#include"taskA.h"
#include"taskA.cpp"

int main(){
    std::cout<<std::endl;

    TaskA one;
    one.hardCodeInput();
    one.getPath();
    //one.printList();
    one.printPath();
    
    std::cout<<std::endl;
}