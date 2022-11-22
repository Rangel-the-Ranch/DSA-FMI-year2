#include<iostream>

//#include"Stacks/MyStack.hpp"
//#include"Stacks/MyStaticStack.hpp"
#include"LinkedList/LinkedListSingle.hpp"


int main(){
    linkedListDouble<int> A;
    A.pushBack(1);
    A.pushBack(2);
    A.pushBack(3);
    A.pushBack(3);
    A.printList();
}
