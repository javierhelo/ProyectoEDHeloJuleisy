#ifndef LINKEDPRIORITYQUEUE_H
#define LINKEDPRIORITYQUEUE_H

#include "LinkedQueue.h"
#include "PriorityQueue.h"
#include <stdexcept>

using std::runtime_error;

template <typename E>
class LinkedPriorityQueue: public PriorityQueue<E>{
private:
    LinkedQueue<E> *elements;
    int size;
    int priorities;

public:
    LinkedPriorityQueue(int priorities){
        if (priorities < 1)
            throw runtime_error("Number of priorities must be positive.");
        elements = new LinkedQueue<E>[priorities];
        size = 0;
        this->priorities = priorities;
    }

    ~LinkedPriorityQueue(){
        delete [] elements;
    }

    void insert(E element, int priority){
        if (priority < 0 || priority >= size)
            throw runtime_error ("Invalid priority.");
        elements[priority].enqueue(element);
        size ++;
    }

    E min(){
        if (size == 0)
            throw runtime_error("Queue is empty.");
        for (int i = 0; i < priorities; i++){
            if (!elements[i].isEmpty())
                return elements[i].frontValue();
        }
        throw runtime_error ("Queue not found.");
    }

    E removeMin(){
        if (size == 0)
            throw runtime_error("Queue is empty.");
        for (int i = 0; i < priorities; i++){
            if (!elements[i].isEmpty()){
                size --;
                return elements[i].dequeue();
            }
        }
        throw runtime_error("Queue not found.");
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }
};

#endif // LINKEDPRIORITYQUEUE_H
