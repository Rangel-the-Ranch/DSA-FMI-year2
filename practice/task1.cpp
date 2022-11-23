#include<iostream>
#include<list>
#include<iterator>

std::list<int> concatenateAndSort(const std::list<int>& A ,const std::list<int>& B){
    std::list<int> result;
    std::list<int>::const_iterator itrA = A.begin();
    std::list<int>::const_iterator itrB = B.begin();
    if(A.empty()){
        return B;
    }
    if(B.empty()){
        return A;
    }
    
    while( 1 ){
        if(itrA == A.end()){
            while(itrB != B.end()){
                result.push_back(*itrB);
                ++itrB;
            }
            break;
        }
        if(itrB == B.end()){
            while(itrA != A.end()){
                result.push_back(*itrA);
                ++itrA;
            }
            break;
        }
        if(*itrA < *itrB){
            result.push_back(*itrA);
            ++itrA;
        }else{
            result.push_back(*itrB);
            ++itrB;
        }
    }

    return result;
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
    std::list<int> B;
    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    B.push_back(2);
    B.push_back(4);
    B.push_back(6);

    std::list<int> C = concatenateAndSort(A,B);
    printList(C);
    
}