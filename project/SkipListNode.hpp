#pragma once

template <typename T>
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
template <typename T>
void SkipListNode<T>::defaultValues(){
    m_Next = nullptr;
    m_Skip = nullptr;
}

template <typename T>
SkipListNode<T>::SkipListNode(const T& newData){
    m_Data = newData;
    defaultValues();
}
template <typename T>
SkipListNode<T>::SkipListNode(){
    defaultValues();
}
template <typename T>
SkipListNode<T>::SkipListNode(const SkipListNode& newNode){
    m_Data = newNode.m_Daya;
    defaultValues();
}
