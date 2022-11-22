#include<iostream>
#include<queue>

template <typename T>
void printQueue(std::queue<T>& q){
    while( !q.empty() ){
        std::cout<<q.front()<<" ";
        q.pop();
    }
    std::cout<<std::endl;
}

template <typename T>
std::queue<T>* taskOne(const size_t n){
    for(size_t i=0; i<n;i++){
        
    }
    
}

int main() {
    std::queue<char> A;
    A.push('a');
    A.push('B');
    A.push('c');
    //printQueue(A);
}