#include<iostream>
using namespace std;

struct myPair{
    size_t a;
    size_t b;
};

template <typename T>
struct Node{
    T value;
    Node<T>* next;
};


template <typename T>
void rotateSublist(Node<int>* list , Node<myPair>* indexPair){
    
    if(list == nullptr){
        throw "Empty list";
    }
    if(indexPair == nullptr){
        return;
    }
    while(indexPair != nullptr){
        Node<T>* itrI = list;
        Node<T>* itrJ = list;
        Node<T>* prevI = nullptr;
        Node<T>* prevJ = nullptr;
        if( indexPair->value.a != indexPair->value.b){
        for(size_t i = 0; i < (indexPair->value.a); i++){
            if(itrI == nullptr){
                throw "Invalid index I";
            }
            itrI = itrI->next;
        }
        for(size_t i = 0; i < (indexPair->value.b); i++){
            if(itrJ == nullptr){
                throw "Invalid index J";
            }
            itrJ = itrJ->next;
        }
        for(size_t i = 1; i < (indexPair->value.a); i++){
            if(prevI == nullptr){
                prevI = list;
            }else{
                prevI = prevI->next;
            }
        }
        for(size_t i = 0; i < (indexPair->value.b); i++){
            if(prevI == nullptr){
                prevJ = list;
            }else{
                prevJ = prevJ->next;
            }
        } 


        Node<T>* newJ = new Node<T>;
        newJ->value = itrJ->value;
        if(prevI == nullptr){
            newJ->next = list;
            list = newJ;
        }else{
            newJ->next = itrI->next;
            prevI->next = newJ;
        }
        if(prevJ != nullptr){
            Node<T>* temp = itrJ->next;
            delete(itrJ);
            prevJ = temp;
        }else{
            Node<T>* temp = itrJ->next;
            delete(itrJ);
            list = temp;
        }
        
    }  //<- if (i!=j)
    }
    
}


int main(){
    
}