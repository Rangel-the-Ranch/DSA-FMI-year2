#pragma once

#include<cstring>
#include <exception>

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
        T const & top()const; //clone of peek

        bool isEmpty()const;
        size_t lenght()const;
        size_t size()const; //clone of lenght

    private:

        static size_t const DEFAULT_STACK_SIZE = 16;
        T* m_Data = nullptr;
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
    m_Data = new T [m_MaxArrSize];
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
size_t MyStack<T>::size()const{
    return m_Size;
}

template<typename T>
void MyStack<T>::push(T const & newObj){
    if(m_Size == m_MaxArrSize){
        resize();
    }

    m_Data[m_Size] = newObj;
    m_Size++;
    return;

}
template<typename T>
void MyStack<T>::push(T&& newObj){
    if(m_Size == m_MaxArrSize){
        resize();
    }

    m_Data[m_Size] = newObj;
    m_Size++;
    return;
}

template<typename T>
void MyStack<T>::resize(){
    m_MaxArrSize *= 2;
    T* temp = new T[m_MaxArrSize];

    for(size_t i=0; i<m_Size; i++){
        temp[i] = m_Data[i];
    }
    delete []m_Data;
    m_Data = temp;
    temp = nullptr;
    return;
}

template<typename T>
T const & MyStack<T>::peek()const{
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }
    return m_Data[m_Size-1];
} 

template<typename T>
T const & MyStack<T>::top()const{
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }
    return m_Data[m_Size-1];
} 

template<typename T>
T const & MyStack<T>::pop(){
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }
    m_Size--;
    return m_Data[m_Size-1];  
} 

template<typename T>
void MyStack<T>::free(){
    delete []m_Data;
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
    
    m_Data = new T [m_MaxArrSize];
    for(size_t i = 0 ; i < m_Size; i++ ){
        m_Data[i] = other.m_Data[i];
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