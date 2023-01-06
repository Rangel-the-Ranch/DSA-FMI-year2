#include<iostream>
#include<cstring>

template<typename T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;
};
const char* removeFirstChar(const char* word){
    if( !strlen(word) ){
        return nullptr;
    }
    return  &word[1];

}

bool readSubWord(const Node<char>* tree,const char* word,size_t rem){
    if(rem == 0){
        return true;
    }else if(tree == nullptr){
        return false;
    }else if(tree->data == word[0]){
        return readSubWord(tree->left, removeFirstChar(word),rem-1) || readSubWord(tree->right, removeFirstChar(word),rem-1) ;
    }else{
        return false;
    }
}

bool readWord(const Node<char>* tree,const char* word){
    const size_t wordSize = strlen(word);
    if( wordSize < 4 ){
        throw "To short word";
    }else if(tree == nullptr){
        return false;
    }

    for(size_t  i=2; i<wordSize-1; i++){
        if( readSubWord(tree->left, word,i) && readSubWord(tree->right, &word[i], wordSize-i) ){
            return true;
        }
        if( readSubWord(tree->right, word,i) && readSubWord(tree->left, &word[i], wordSize-i) ){
            return true;
        }
    }
    return false;
}

size_t minLevel(const Node<char>* tree){
    if(tree == nullptr){
        throw "no tree";
    }
    return 0;
}



int main(){
    Node<char> a1,a2,a3,a4,a5,a6,a7,a8,a9;
    
    a1.data = 'F';
    a1.left = &a2;
    a1.right = &a3;
    a2.data = 'B';
    a2.left = &a4;
    a2.right = &a5;
    a4.data = 'A';
    a5.data = 'D';
    a5.left = &a6;
    a5.right = &a7;
    a6.data = 'C';
    a7.data = 'E';
    a3.data = 'G';
    a3.right = &a8;
    a8.data ='I';
    a8.right = &a8;
    a9.data = 'H';
    
    std::cout<<readWord(&a1,"GIBDC")<<std::endl;
    std::cout<<readWord(&a1,"GIBD")<<std::endl;
    std::cout<<readWord(&a1,"GIBCD")<<std::endl;
    std::cout<<readWord(&a1,"GHBD")<<std::endl;
    std::cout<<readWord(&a1,"GIB")<<std::endl;
    
}