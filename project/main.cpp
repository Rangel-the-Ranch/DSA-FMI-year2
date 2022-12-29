//#include<iostream>

#include"SkipList.hpp"


int main(){
    SkipList<int> list;
    list.pushBack(5);
    list.pushBack(4);
    list.pushBack(3);
    list.pushBack(2);
    list.popBack();
    list.popFront();
    list.print();
}