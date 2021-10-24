#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <ostream>
#include "Queue.h"
#include "Node.h"
#include <stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class LinkedQueue: public Queue<E>{
private:
    Node<E> *front;
    Node<E> *rear;
    int size;

public:
    LinkedQueue(){
        rear = front = new Node<E>();
        size = 0;
    }

    ~LinkedQueue(){
        clear();
        delete front;
    }

    void enqueue(E element){
        rear = rear->next = new Node<E>(element);
        size++;
    }

    E dequeue(){
        if (size == 0)
            throw runtime_error("Queue is empty.");
        E result = front->next->element;
        Node<E> *temp = front->next;
        front->next = temp->next;
        delete temp;
        size--;
        if (size == 0)
            rear = front;
        return result;
    }

    E frontValue(){
        if (size == 0)
            throw runtime_error("Queue is empty.");
        return front->next->element;
    }

    void clear(){
        while(front->next != nullptr){
            rear = front->next;
            front->next = rear->next;
            delete rear;
        }
        rear = front;
        size = 0;
    }

    bool isEmpty(){
        return size == 0;
    }

    int getSize(){
        return size;
    }

    void print(){
        Node<E> *temp = front->next;
        cout << "[ ";
        for (int i = 0; i < size; i++){
            cout << temp->element << " ";
            temp = temp->next;
        }
        cout << "]";
        delete temp;
    }
};

#endif // LINKEDQUEUE_H
