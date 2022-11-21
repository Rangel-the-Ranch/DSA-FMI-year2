#include"Queue.hpp"

template <typename P>
class prioQueue{
    private:
        static const size_t DEFAULT_STARTING_ARR_SIZE = 16;
        static const size_t DEFAULT_STARTING_PRIO_LANES = 5;

        size_t size;
        MyQueue<P>* queues;
        size_t numberOfQueues;
        

        void free();
        void copyFrom(const prioQueue<P>& other);

        void resize();

    public:
        prioQueue();
        prioQueue(const size_t prioLanesNumber);
        ~prioQueue();

        prioQueue(const prioQueue<P>& other);
        prioQueue<P>& operator=(const prioQueue<P>& other);

        void push(const size_t index ,const P& newData);
        void push(const size_t index ,P&& newData);

        const P& peek()const;
        void pop();

        const bool isEmpty()const;

        void addLane();
        void removeLane(const size_t index);
};

template <typename P>
void prioQueue<P>::free(){
    delete []this->queues;
}

template <typename P>
void prioQueue<P>::copyFrom(const prioQueue<P>& other ){
    this->numberOfQueues = other.numberOfQueues;
    this->size = other.size;
    queues = new MyQueue<P>[this->size];
    for(int i=0; i<numberOfQueues;i++){
        this->queues = other.queues;
    }

}




template <typename P>
prioQueue<P>::prioQueue(){
    this->queues = new MyQueue<P> [this->DEFAULT_STARTING_ARR_SIZE];
    this->numberOfQueues = this->DEFAULT_STARTING_PRIO_LANES;
    this->size = this->DEFAULT_STARTING_ARR_SIZE;
}
template <typename P>
prioQueue<P>::prioQueue(const size_t prioQueues){
    this->queues = new MyQueue<P> [this->DEFAULT_STARTING_ARR_SIZE];
    this->numberOfQueues = prioQueues;
    this->size = this->DEFAULT_STARTING_ARR_SIZE;
}
template <typename P>
prioQueue<P>::~prioQueue(){
    free();
}
template <typename P>
prioQueue<P>::prioQueue(const prioQueue<P>& other){
    copyFrom(other);
}

template <typename P>
prioQueue<P>& prioQueue<P>::operator=(const prioQueue<P>& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}


template <typename P>
void prioQueue<P>::push(const size_t index, const P& newData){
    if(index >= this->numberOfQueues){
        throw std::logic_error("Not existing queue");
    }
    this->queues[index].push( newData );
}

template <typename P>
void prioQueue<P>::push(const size_t index, P&& newData){
    if(index >= this->numberOfQueues){
        throw std::logic_error("Not existing queue");
    }
    this->queues[index].push( newData );
}

template <typename P>
const P& prioQueue<P>::peek()const{
    for(int i = 0; i<this->numberOfQueues; i++){
            if( queues[i].isEmpty() == false ){
                return queues[i].peek();

            }
        }
    throw std::logic_error("Empty queues!");
}

template <typename P>
void prioQueue<P>::pop(){
    for(int i = 0; i<this->numberOfQueues; i++){
            if( queues[i].isEmpty() == false ){
                queues[i].pop();
                return;
            }
        }
    throw std::logic_error("Empty queues!");
}
template <typename P>
const bool prioQueue<P>::isEmpty()const{
    for(int i=0; i<this->numberOfQueues;i++){
        if( this->queues[i].isEmpty() == false){
            return false;
        }
    }
    return true;
}

template <typename P>
void prioQueue<P>::addLane(){
    if(this->numberOfQueues >= this->size){
        resize();
    }
    this->numberOfQueues++;
}
template <typename P>
void prioQueue<P>::resize(){
    this->size = this->size*2;
    MyQueue<P>* buffer = new MyQueue<P> [this->size];
    for(int i=0; i<this->numberOfQueues;i++){
        buffer[i] = queues[i];
    }
    delete []queues;
    queues = buffer;
    buffer = nullptr;
}

template <typename P>
void prioQueue<P>::removeLane(const size_t index){
    for(int i = index; i<numberOfQueues;i++){
        queues[i] = queues[ i + 1 ];
    }
    numberOfQueues--;
}