#pragma once

template <typename T>
class SkipListNode{
    public:
        SkipListNode(const T& newData){
            data = newData;
        }


    private:
        
        SkipListNode* next = nullptr;
        
        T data;    
            
};