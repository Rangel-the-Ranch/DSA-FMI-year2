#pragma once

#include <exception>

template<typename T>
class MyStaticStack{
    public:
        static size_t const MAX_STACK_SIZE = 1024;

        void push(T const & newObj);
        void push(T&& object);
        T const & pop();
        T const & peek()const;
        T const & top()const; //clone of peek

        bool isEmpty()const;
        bool isFull()const;
        size_t lenght()const;
        size_t size()const; //clone of lenght

    private:
        T m_Data[MAX_STACK_SIZE];
        size_t m_Size = 0;  
};

template<typename T>
void MyStaticStack<T>::push(T const & newObj){
    if( isFull() ){
        throw std::logic_error("Full stack!");
    }
    m_Data[m_Size] = newObj;
    m_Size++;
    return;
}

template<typename T>
void MyStaticStack<T>::push(T&& newObj){
    if( isFull() ){
        throw std::logic_error("Full stack!");
    }else{
        m_Data[m_Size] = newObj;
        m_Size++;
        return;
    }
}

template<typename T>
T const & MyStaticStack<T>::pop(){
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }else{
        m_Size--;
        return m_Data[m_Size];
    }
}

template<typename T>
T const & MyStaticStack<T>::peek()const{
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }else{
        return m_Data[m_Size-1];
    }
}

template<typename T>
T const & MyStaticStack<T>::top()const{
    if( isEmpty() ){
        throw std::logic_error("Empty stack!");
    }else{
        return m_Data[m_Size-1];
    }
}

template<typename T>
bool MyStaticStack<T>::isEmpty()const{
    return !m_Size;
}
template<typename T>
bool MyStaticStack<T>::isFull()const{
    return !(MAX_STACK_SIZE - m_Size);
}
template<typename T>
size_t MyStaticStack<T>::lenght()const{
    return m_Size;
}

template<typename T>
size_t MyStaticStack<T>::size()const{
    return m_Size;
}

