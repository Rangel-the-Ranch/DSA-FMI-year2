#include<iostream>
#include<list>
#include<iterator>

void rearrange(std::list<int>& list){
    if(list.empty()){
        return;
    }
    std::list<int>::iterator even;// = list.begin();
    std::list<int>::iterator odd;// = list.begin();
    
    for(std::list<int>::iterator it = list.begin() ; it != list.end(); it++){
        if( (*it) % 2 ){
            
        }else{

        }
    }


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
    std::list<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);

}