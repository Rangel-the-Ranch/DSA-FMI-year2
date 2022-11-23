struct listElem{
    listElem* previous = nullptr;
    listElem* next = nullptr;
    T data;    
    listElem(const T& newData){
        data = newData;
    }
};