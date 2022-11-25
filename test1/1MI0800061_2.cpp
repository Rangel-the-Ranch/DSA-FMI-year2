#include<iostream>
#include<cmath>
using namespace std;

template <typename T>
struct Node{
    T value;
    Node<T>* next;
};

bool makeTotal(Node<int>* beg){
    if( beg == nullptr || beg->next == nullptr ){
        return false;
    }
    Node<int>* it = beg->next;
    Node<int>* prev = beg;
    bool isTrue = true;
    while( it != nullptr ){
        if( abs( (it-> value)-(prev->value) ) != 1){
            isTrue = false;
            break;
        }
        prev = it;
        it = it->next;
    }
    if(isTrue){
        return true;
    }
    it = beg->next;
    prev = beg;
    while( it != nullptr){
        
        if( abs( (it-> value)-(prev->value) ) == 1){
            Node<int>* toDelete = it;
            it = it->next;
            delete toDelete;
            prev->next = it; 
            if(it == nullptr){
                break;
            }
        }
        prev = it;
        it = it->next;
    }
    return 0;

}



int main(){
    Node<int> A,B,C,D;
    A.value = 2;
    B.value = 3;
    C.value = 4;
    D.value = 5;
    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = nullptr;
    cout<<makeTotal(&B);
    //cout<<" "<<(A.next)->value;
}