#include<iostream>

template<typename T>
struct DLListElem{
    T data;
    DLListElem<T>* next;
    DLListElem<T>* prev;
};

template<typename T>
DLListElem<T>* moveFoward(DLListElem<T>* start,int N){
    DLListElem<T>* itr = start;
    for(int i=0; i<N; i++){
        if(itr->next == nullptr){
            return itr;
        }
        itr=itr->next;
    } 
    return itr;
}

template<typename T>
void sordDeciding(DLListElem<T>*start, DLListElem<T>* end){
    if(start == nullptr || end == nullptr){
        return;
    }
    if(start == end){
        return
    }
    size_t listSize=0;
    DLListElem<T>* itr = start;
    while (itr != end){
        listSize++;
        itr = itr->next;
    }
    for(int i=0; i<listSize; i++){
        DLListElem<T>* itr = moveFoward(start,i);
        for(int j=i; j<listSize; j++){
            DLListElem<T>* temp = moveFoward(start,j);
            if(itr->data < temp->data){
                T tempData = itr->data;
                itr->data = temp->data;
                temp->data = itr->data;
            }
        }
    }
}
//Сложност по време o(n^3)
int main(){
    
}