#pragma once





template <typename T>
class linkedListDouble{
    private:
        struct listElem{
            listElem* previous = nullptr;
            listElem* next = nullptr;
            T data;    
            listElem(const T& newData){
                data = newData;
            }
        };

        void free();    

    public:
    
        linkedListDouble();
        void pushBack(const listElem& newListElem);
        void pushFront(const listElem& newListElem);
        void popBack();
        void popFront();
        const T& peekFront()const;
        const T& peekBack()const;
        bool empty()const;
        size_t getSize()const;

        void printList()const;

        class Iterator{
            private:
                listElem* position;

                Iterator(listElem* newElm) : position { newElm } {}
            public: 
                Iterator& operator++(){
                    if(position->next){
                        position = position->next;
                    }
                    return *this;
                    }
                Iterator& operator--(){
                    if(position->previous){
                        position = position->previous;
                    }
                    return *this;
                }
                T& operator*(){
                    return position->data;
                }
                bool operator==(const Iterator& other) const {
                    return other.position == position;
                }

                bool operator!=(const Iterator& other) const {
                    return !(*this == other);
                }
            friend class linkedListDouble;
        };

    private: 
        
        listElem* m_start = nullptr;
        listElem* m_end = nullptr;
        size_t m_size = 0;
};
template<typename T>
void linkedListDouble<T>::free(){
    while(m_end){
        popFront();
    }
    m_size = 0;  
}

template<typename T>
linkedListDouble<T>::linkedListDouble(){
    m_start = nullptr;
    m_end = nullptr;
    m_size = 0;
}

template<typename T>
void linkedListDouble<T>::pushBack(const listElem& newListElem){
    listElem* toPush = new listElem(newListElem);

    if( m_start == nullptr){
        m_start = toPush;
        m_end = toPush;
    }else{
        m_end->next = toPush;
        toPush->previous = m_end;
        toPush->next = nullptr;
        m_end = toPush;
    }
    m_size++;
}
template<typename T>
void linkedListDouble<T>::pushFront(const listElem& newListElem){
    listElem* toPush = new listElem(newListElem);

    if( m_end == nullptr){
        m_start = toPush;
        m_end = toPush;
    }else{
        m_start->previous = toPush;
        toPush->previous = nullptr;
        toPush->next = m_start;
        m_start = toPush;
    }
    m_size++;
}


template<typename T>
void linkedListDouble<T>::popBack(){
    if(m_end == nullptr){
        throw "Empty queue";
    }else if(m_start == m_end){
        delete m_start;
        m_start = nullptr;
        m_end = nullptr;
    }else{
        m_end = m_end->previous;
        delete m_end->next;
        m_end->next = nullptr;
    }
    m_size--;
}
template<typename T>
void linkedListDouble<T>::popFront(){
    if(m_start == nullptr){
        throw "Empty queue";
    }else if(m_start == m_end){
        delete m_start;
        m_start = nullptr;
        m_end = nullptr;
    }else{
        m_start = m_start->next;
        delete m_start->previous;
        m_start->previous = nullptr;
    }
    m_size--;
}

template<typename T>
const T& linkedListDouble<T>::peekBack()const{
    if(m_end == nullptr){
         throw "Empty queue";
    }
    return m_end->data;
}
template<typename T>
const T& linkedListDouble<T>::peekFront()const{
    if(m_start == nullptr){
         throw "Empty queue";
    }
    return m_start->data;
}
template<typename T>
bool linkedListDouble<T>::empty()const{
    return !m_start;
}
template<typename T>
size_t linkedListDouble<T>::getSize()const{
    return m_size;
}
template<typename T>
void linkedListDouble<T>::printList()const{
    listElem* iter = m_start;
    if(m_start == nullptr){
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
