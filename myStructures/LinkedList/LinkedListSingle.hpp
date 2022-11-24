#pragma once

template <typename T>
class linkedListSingle{
    private:
        struct listNode{
            listNode* next = nullptr;
            T data;

            listNode(const T& newData){ 
                data = newData;
                next = nullptr;
            }    
            listNode(const listNode& newNode){
                data = newNode.date;
                next = nullptr;
            }        
        };

        listNode* m_begin = nullptr;
        listNode* m_end = nullptr;
        size_t m_size = 0;
        
        void free();        

    public:
        void pushBack(const T& newData);
        void pushFront(const T& newData);
        void popBack();
        void popFront();
        const T& peekBack()const;
        const T& peekFront()const;
        bool empty()const;
        size_t getSize()const;
        void reverce();
        void printList()const;

        class Iterator{
            public:
                Iterator* operator++(){
                    if(ptr->next != nullptr){
                        ptr = ptr->next;
                    }
                }
                T& operator*()const{
                    if(ptr != nullptr){
                        return ptr->data;
                    }
                    throw "Unused iterator";
                }
                bool operator==(const Iterator& other)const{
                    return ptr == other.ptr;
                }
                
                Iterator(listNode* arg){
                    ptr = arg;
                }

                friend class linkedSingleList;
            private:
                listNode* ptr = nullptr;
                
        };

        Iterator begin(){
            return Iterator(m_begin);
        };
        Iterator end(){
            return Iterator(m_end);
        };
};
template <typename T>
void linkedListSingle<T>::reverce(){
    if(empty() || m_begin == m_end){
        return;
    }
    listNode* newEnd = m_begin;
    listNode* helper = nullptr;
    listNode* it = m_begin;
    while(  it != nullptr ){
        listNode* temp = it->next;
        it->next = helper;
        helper = it;
        it = temp;
    }
    m_begin = helper;

    m_end = newEnd;
}

template <typename T>
bool linkedListSingle<T>::empty()const{
    return !m_end;
}
template <typename T>
size_t linkedListSingle<T>::getSize()const{
    return m_size;
}



template <typename T>
void linkedListSingle<T>::pushBack(const T& newData){
    listNode*  newElem = new listNode(newData);
    if(m_end == nullptr){
        m_end = newElem;
        m_begin = newElem;
    }else{
        
        m_end->next = newElem;
        m_end = m_end-> next;
    }
    m_size++;
}
template <typename T>
void linkedListSingle<T>::pushFront(const T& newData){
    listNode*  newElem = new listNode(newData);
    if(m_begin == nullptr){
        m_end = newElem;
        m_begin = newElem;
    }else{
        newElem->next = m_begin;
        m_begin = newElem;
    }
    m_size++;
}
template <typename T>
void linkedListSingle<T>::popBack(){
    if(m_end == nullptr){
        throw "Empty list";
    }else if(m_begin == m_end){
        delete m_begin;
        m_begin = nullptr;
        m_end = nullptr;
        m_size--;
    }else{
        listNode* iter = m_begin;
        while (iter->next->next != nullptr){
            iter = iter->next;
        }
        delete iter->next;
        iter->next = nullptr;
        m_size--;
        iter = nullptr;
    }
    
}
template <typename T>
void linkedListSingle<T>::popFront(){
    if(m_begin == nullptr){
        throw "Empty list";
    }else if(m_begin == m_end){
        delete m_begin;
        m_begin = nullptr;
        m_end = nullptr;
        m_size--;
    }else{
        listNode* temp = m_begin;
        m_begin = m_begin->next;
        delete temp;
        m_size--;
    }  
}
template <typename T>
const T& linkedListSingle<T>::peekBack()const{
    if(m_end == nullptr){
        throw "Empty list";
    }
    return m_end->data;
}
template <typename T>
const T& linkedListSingle<T>::peekFront()const{
    if(m_begin == nullptr){
        throw "Empty list";
    }
    return m_begin->data;
}
template <typename T>
void linkedListSingle<T>::printList()const{
    listNode* iter = m_begin;
    if(m_begin == nullptr){
        return;
    }
    while (iter->next){
        std::cout<<iter->data;
        std::cout<<" -> ";
        iter = iter->next;
    }
    std::cout<<iter->data;
    std::cout<<std::endl;
}
template <typename T>
void linkedListSingle<T>::free(){
    while( !empty() ){
        popFront();
    }
    m_size = 0;
}