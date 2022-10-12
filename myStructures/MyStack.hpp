#pragma once

#include<cstring>
#include <exception>

//BIG 4

template<typename T>
class MyStack{
    public:
        MyStack();
        ~MyStack();
        MyStack(MyStack const  & other);

        MyStack& operator=(MyStack const & other);
        
        void push(T const & newObj);
        void push(T&& object);
        T const & pop();
        T const & peek()const;

        bool isEmpty()const;
        size_t lenght()const;

    private:
    
        static size_t const DEFAULT_STACK_SIZE = 1;
        T* m_Array = nullptr;
        size_t m_Size = 0;
        size_t m_MaxArrSize = 1;

        void free();
        void copyFrom(MyStack const & other);
        void resize();
};

template<typename T>
MyStack<T>::MyStack(){
    m_Size = 0;
    size_t m_MaxArrSize = DEFAULT_STACK_SIZE;
    m_Array = new T [m_MaxArrSize];
}
template<typename T>
MyStack<T>::~MyStack(){
    free();
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
        resize();
    }

    m_Array[m_Size] = newObj;
    m_Size++;
    return;

}
template<typename T>
void MyStack<T>::push(T&& newObj){
    if(m_Size == m_MaxArrSize){
        resize();
    }

    m_Array[m_Size] = newObj;
    m_Size++;
    return;
}

template<typename T>
void MyStack<T>::resize(){
    m_MaxArrSize *= 2;
    T* temp = new T[m_MaxArrSize];

    for(size_t i=0; i<m_Size; i++){
        temp[i] = m_Array[i];
    }
    delete []m_Array;
    m_Array = temp;
    temp = nullptr;
    return;
}

template<typename T>
T const & MyStack<T>::peek()const{
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }
    return m_Array[m_Size-1];
} 

template<typename T>
T const & MyStack<T>::pop(){
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }
    m_Size--;
    return m_Array[m_Size-1];  
} 

template<typename T>
void MyStack<T>::free(){
    delete []m_Array;
    return;
} 

template<typename T>
MyStack<T>::MyStack(MyStack const & other){
    copyFrom(other);
}

template<typename T>
void MyStack<T>::copyFrom(MyStack const & other){
    m_Size = other.m_Size;
    m_MaxArrSize = other.m_MaxArrSize;
    
    m_Array = new T [m_MaxArrSize];
    for(size_t i = 0 ; i < m_Size; i++ ){
        m_Array[i] = other.m_Array[i];
    }
    return;
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(MyStack<T> const & other){
	if (this != &other){
		free();
		copyFrom(other);
	}
	return *this;
}