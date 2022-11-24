#include<iostream>

//#include"Stacks/MyStack.hpp"
//#include"Stacks/MyStaticStack.hpp"
#include"LinkedList/LinkedListSingle.hpp"
#include"LinkedList/LinkedListDouble.hpp"


int main(){
    linkedListSingle<int> A;
    A.pushBack(1);
    A.pushBack(2);
    A.pushBack(3);
    A.pushBack(3);
    A.popBack();
    A.popFront();
    A.pushFront(-1);
    A.printList();
    A.reverce();
    A.printList();
    linkedListSingle<int>::Iterator it = A.end();

    std::cout<<*it;
    
    //std::cout<<A.empty()<<A.getSize();
    
}
