class Iterator{
    private:
        listElem* position;

        Iterator(listElem* newElm){
            position = newElm;
        }
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
class ConstIterator{
    private:
        const listElem* position;

        ConstIterator(listElem* newElm){
            position = newElm;
        }
    public: 
        ConstIterator& operator++(){
            if(position->next){
                position = position->next;
            }
            return *this;
        }
                
        ConstIterator& operator--(){
            if(position->previous){
                position = position->previous;
            }
            return *this;
        }
        const T& operator*(){
            return position->data;
        }
        bool operator==(const ConstIterator& other) const {
            return other.position == position;
        }

        bool operator!=(const ConstIterator& other) const {
            return !(*this == other);
        }
    friend class linkedListDouble;
};
