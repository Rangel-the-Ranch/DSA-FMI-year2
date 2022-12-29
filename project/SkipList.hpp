#pragma once

#include<iostream>

template<typename T>
class SkipList{
    private:
        struct SkipListNode{
            public:
                SkipListNode* m_Next = nullptr;
                SkipListNode* m_Skip = nullptr;
                T m_Data;  

                SkipListNode();
                SkipListNode(const T& newData);
                SkipListNode(const SkipListNode& newNode);

            private:
                void defaultValues();
        };

    public:
        SkipList();
        SkipList(const SkipListNode* newNode);
        ~SkipList();

        void pushBack(const T& newData);
        void pushFront(const T& newData);
        void popBack();
        void popFront();
        const T& peekBack()const;
        const T& peekFront()const;

        bool isEmpty()const;
        unsigned int getSize()const;

        void print()const;

        class Iterator{
            public:
                Iterator();
                Iterator(SkipListNode* newPtr);

                bool operator==(const Iterator& other)const;
                bool operator!=(const Iterator& other)const;
                T& operator*();
                void operator++();
                void operator+=(const unsigned int moves);
                void skip();
                bool isNull()const;

                void addSkip(const Iterator& newSkip);

                friend class SkipListNode;
            private:
                SkipListNode* m_Ptr = nullptr;
        };

        SkipListNode* begin(){
            return m_Begin;
        }
        


        
    private:
        SkipListNode* m_Begin = nullptr;
        SkipListNode* m_End = nullptr;
        unsigned int m_Size = 0;

        void defaultValues();
        void free();


};

template<typename T>
bool SkipList<T>::Iterator::isNull()const{
    return !m_Ptr;
}

template<typename T>
SkipList<T>::SkipList(const SkipListNode* newNode){
    pushBack(newNode);
}

template<typename T>
SkipList<T>::SkipList(){
    defaultValues();
}

template<typename T>
SkipList<T>::~SkipList(){
    free();
}

template<typename T>
void SkipList<T>::free(){
    if(m_Begin){
        popBack();
    }
}

template<typename T>
void SkipList<T>::Iterator::addSkip(const Iterator& newSkip){
    if(m_Ptr == nullptr){
        throw "Iterator not existing";
    }else{
        m_Ptr->m_Skip = newSkip.m_Ptr;
    }
}

template<typename T>
void SkipList<T>::Iterator::skip(){
    if(m_Ptr == nullptr){
        throw "Iterator not existing";
    }else if( m_Ptr ->m_Skip ){
        m_Ptr = m_Ptr -> m_Skip;
    }
}

template<typename T>
void SkipList<T>::Iterator::operator+=(const unsigned int moves){
    if(m_Ptr == nullptr){
        throw "Iterator not existing";
    }else if(moves <= 0){
        return;
    }else if( m_Ptr ->m_Next ){
        m_Ptr = m_Ptr -> m_Next;
        operator+=(moves-1);
    }
}

template<typename T>
void SkipList<T>::Iterator::operator++(){
    if(m_Ptr == nullptr){
        throw "Iterator not existing";
    }else if( m_Ptr ->m_Next ){
        m_Ptr = m_Ptr -> m_Next;
    }
}


template<typename T>
T& SkipList<T>::Iterator::operator*(){
    return m_Ptr->m_Data;
}

template<typename T>
bool SkipList<T>::Iterator::operator==(const Iterator& other)const{
    return m_Ptr == other.m_Ptr;
}
template<typename T>
bool SkipList<T>::Iterator::operator!=(const Iterator& other)const{
    return !(m_Ptr == other.m_Ptr);
}

template<typename T>
SkipList<T>::Iterator::Iterator(SkipListNode* newPtr){
    m_Ptr = newPtr;
}
template<typename T>
SkipList<T>::Iterator::Iterator(){
    m_Ptr = m_Begin;
}

template<typename T>
void SkipList<T>::print()const{
    if(m_Begin == nullptr){
        std::cout<<"Empty list";
    }else{
        SkipListNode* iter = m_Begin;
        while(iter != m_End){
            std::cout<<iter->m_Data;
            std::cout<<" -> ";
            iter = iter->m_Next;
        }
        std::cout<<iter->m_Data;
    }
    std::cout<<std::endl;
}

template<typename T>
unsigned int SkipList<T>::getSize()const{
    return m_Size;
}
template<typename T>
bool SkipList<T>::isEmpty()const{
    return !m_Size;
}

template<typename T>
const T& SkipList<T>::peekFront()const{
    return m_Begin->m_Data;
}
template<typename T>
const T& SkipList<T>::peekBack()const{
    return m_End->m_Data;
}

template<typename T>
void SkipList<T>::popFront(){
    if( !m_Begin ){
        throw "Empty list";
    }else if(m_Begin == m_End){
        delete m_Begin;
        m_Begin = nullptr;
        m_End = nullptr;
    }else{
        SkipListNode* temp = m_Begin;
        m_Begin = m_Begin->m_Next;
        delete temp;
        temp = nullptr;
    }
    m_Size--;
}

template<typename T>
void SkipList<T>::popBack(){
    if( !m_Begin ){
        throw "Empty list";
    }else if(m_Begin == m_End){
        delete m_Begin;
        m_Begin = nullptr;
        m_End = nullptr;
    }else{
        SkipListNode* iter = m_Begin;
        while(iter->m_Next != m_End){
            iter = iter->m_Next;
        }
        delete iter->m_Next;
        iter->m_Next = nullptr;
        m_End = iter;
        iter = nullptr;
    }
    m_Size--;
}

template<typename T>
void SkipList<T>::pushFront(const T& newData){
    m_Size++;
    SkipListNode* toPush = new SkipListNode(newData);
    if( !m_Begin ){
        m_Begin = toPush;
        m_End = toPush;
    }else{
        toPush->m_Next = m_Begin;
        m_Begin = toPush;
    }
}
template<typename T>
void SkipList<T>::pushBack(const T& newData){
    m_Size++;
    SkipListNode* toPush = new SkipListNode(newData);
    if( !m_Begin ){
        m_Begin = toPush;
        m_End = toPush;
    }else{
        m_End->m_Next = toPush;
        m_End = toPush;
    }
}

template<typename T>
void SkipList<T>::defaultValues(){
    m_Begin = nullptr;
    m_End = nullptr;
    m_Size = 0;
}

template <typename T>
void SkipList<T>::SkipListNode::defaultValues(){
    m_Next = nullptr;
    m_Skip = nullptr;
}

template <typename T>
SkipList<T>::SkipListNode::SkipListNode(const T& newData){
    m_Data = newData;
    defaultValues();
}

template <typename T>
SkipList<T>::SkipListNode::SkipListNode(){
    defaultValues();
}
template <typename T>
SkipList<T>::SkipListNode::SkipListNode(const SkipListNode& newNode){
    m_Data = newNode.m_Daya;
    defaultValues();
}
