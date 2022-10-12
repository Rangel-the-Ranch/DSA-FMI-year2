#pragma once

#include<cstring>
#include <exception>

//BIG 4

template<typename T>
class MyStack{
    public:
        MyStack();
        //~MyStack();
        
        void push(T const & newObj);
        void push(T&& object)
        T* pop();
        T* peek()const;

        bool isEmpty()const;
        size_t lenght()const;

    private:
        static size_t const DEFAULT_STACK_SIZE = 16;
        T* m_Array = nullptr;
        size_t m_Size = 0;
        size_t m_MaxArrSize = 1;

        //free();
        //copyFrom();
        //resize();
};

template<typename T>
MyStack<T>::MyStack(){
    m_Size = 0;
    size_t m_MaxArrSize = DEFAULT_STACK_SIZE;
    m_Array = new T [m_MaxArrSize];
}

template<typename T>
bool MyStack<T>::isEmpty()const{
    return !m_Size;
}

template<typename T>
size_t MyStack<T>::lenght()const{
    return m_Size;
}

template<typename T>
void MyStack<T>::push(T const & newObj){
    if(m_Size == m_MaxArrSize){
        //resize();
    }
    delete m_Array[m_Size];//////////////////////////////////////////////////////////////////

    m_Array[m_Size] = newObj;
    m_Size++;
    return;

}
template<typename T>
void MyStack<T>::push(T&& newObj){
    if(m_Size == m_MaxArrSize){
        //resize();
    }
    delete m_Array[m_Size];

    m_Array[m_Size] = newObj;
    m_Size++;
    return;
}

template<typename T>
T* MyStack<T>::peek()const{
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }
    return m_Array[m_Size-1];
} 

template<typename T>
T* MyStack<T>::pop(){
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }
    m_Size--;
    return m_Array[m_Size-1];  
} 