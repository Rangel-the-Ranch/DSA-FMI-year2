#include <iostream>

void f(int  & a){
    //a += 5;
    std::cout<<sizeof(a)<<" ";
    std::cout<<&a<<" ";
    std::cout<<sizeof(&a)<<" ";
}
void g(int * const a){
    //*a += 5;
    std::cout<<sizeof(*a)<<" ";
    std::cout<<a<<" ";
    std::cout<<sizeof(a)<<" ";
}
//volatile
int main(){
    int a;
    f(a);
    std::cout<<std::endl;
    g(&a);
    //std::cout<< a << " " << b; 
}