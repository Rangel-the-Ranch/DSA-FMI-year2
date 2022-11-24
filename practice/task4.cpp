#include<iostream>
#include<list>
#include<iterator>

void kgroups(std::list<int>& list, const size_t k){
    if(list.empty()){
        std::cout<<"Empty list"<<std::endl;
        return;
    }
    if(k >= list.size()){
        list.reverse();
        return;
    }

    std::list<int> A;
    std::list<int>::iterator it=list.begin();
    for(size_t i=0; i<k; i++){
        A.push_back(*it);
        it = list.erase(it);
    }
    std::list<int> B;

    for(size_t i=0; i<k; i++){
        B.push_back(*it);
        it = list.erase(it);
    }

    A.reverse();
    B.reverse();
    A.splice(A.end(),B);
    A.splice(A.end(),list);
    list = A;
}


void printList(const std::list<int> list){
    if(list.empty()){
        std::cout<<"Empty list"<<std::endl;
        return;
    }

    
    std::list<int>::const_iterator it = list.begin();
    while(it != list.end() ){
        std::cout<<*it;
        if(it != --list.end()){
            std::cout<<" -> ";
        }
        ++it;
    }
    std::cout<<std::endl;
}

int main(){
    std::list<int> A = {1,2,3,4,5};

    kgroups(A,2);
    printList(A);

}