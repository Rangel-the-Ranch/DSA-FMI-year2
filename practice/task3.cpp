#include<iostream>
#include<list>
#include<iterator>

void oddEvenList(std::list<int>& list){
    if(list.empty()){
        return;
    }
    std::list<int> result;
    
    for(std::list<int>::iterator it = list.begin(); it != list.end() || it != (list.end()--); std::advance(it ,2)){
        result.push_back(*it);
        it = list.erase(it);
        --it;

    }
    result.splice(result.end(),list);
    list = result;
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
    std::list<int> A = {1,2,3,4,5,2,1,0};


    oddEvenList(A);
    printList(A);

}