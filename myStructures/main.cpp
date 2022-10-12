#include<iostream>

#include"MyStack.hpp"

int main(){
    MyStack<int> A;
    A.push(10);
    A.push(11);
    A.push(12);
    MyStack<int> B;
    B = A;
    std::cout<<B.peek();
    std::cout<<B.pop();
    std::cout<<B.peek();
}