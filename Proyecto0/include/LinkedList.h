//Clase hija de List, implementa las funciones
//descritas en List.h utilizando listas enlazadas
//con nodos
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include"Node.h"
#include <stdexcept>
 using std::runtime_error;
 using std::cout;
 using std::endl;

template <typename E>
class LinkedList : public List<E> { //: significa que hereda y es public
private:
    Node<E> *head;
    Node<E> *current;
    Node<E> *tail;
    int size;

public:
    LinkedList(){
        tail = current = head = new Node<E>(); //crea nodo especial puntero next = null
        size = 0;
    }
    ~LinkedList(){
        clear();
        delete head;
    }
    void insert(E element){
        current->next = new Node<E>(element, current->next);
        if (current == tail){
            tail = current->next;
        }
        size++;
    }
    void append(E element){
        tail = tail->next = new Node<E>(element);
        size++;
    }
    E remove(){
        if(size == 0)
            throw runtime_error("List is empty.");
        if (current->next == nullptr)
            throw runtime_error("No current element.");
        E result = current->next->element;
        Node<E> *temp = current->next; //variable local temp puntero a nodo a eliminar(actual)
        current->next = temp->next;
        if (temp == tail)
            tail = current;
        delete temp; //es un nodo �nico
        size--;
        return result;
    }
    void clear(){
        while(head->next != nullptr){
            current = head->next;
            head->next = current->next;
            delete current;
        }
        current = tail = head;
        size = 0;
    }
    E getElement(){
        if (size == 0)
            throw runtime_error("List is empty");
        if (current->next == nullptr)
            throw runtime_error("No current element");
        return current->next->element;
    }
    void goToStart(){
        current = head;
    }
    void goToEnd(){
        current = tail;
    }
    void goToPos(int pos){
        if (pos < 0 || pos > size)
            throw runtime_error("List index out of range.");
        current = head;
        for(int i = 0; i < pos; i++){
            current = current->next;
        }

    }
    void next(){
        if(current != tail)
            current = current->next;
    }
    void previous(){
        if (current != head){
            Node<E> *temp = head;
            while(temp->next != current)
                temp = temp->next;
            current = temp;
        }
    }
    bool atStart(){
        return current == head;
    }
    bool atEnd(){
        return current == tail;
    }
    int getPos(){
        int pos = 0;
        Node<E> *temp = head;
        while(temp != current){
            temp = temp->next;
            pos++;
        }
        return pos;
    }
    int getSize(){
        return size;
    }
    void print(){
        Node<E> *oldCurrent = current;
        cout << "[ ";
        for (goToStart(); !atEnd(); next())
            cout << getElement() << " ";
        cout << "]";
        current = oldCurrent;
    }

    //Nuevas Funciones
    int indexOf(E element){
        Node<E> *temp = current;
        for(goToStart(); !atEnd(); next()){
            if(current->element == element)
                return getPos();
        }
        current = temp;
        return -1;
    }
    bool contains(E element){
        Node<E> *temp = current;
        for (goToStart(); !atEnd(); next()){
            if (getElement() == element){
                current = temp;
                return true;
            }
        }
        return false;
    }

    void extend(List<E> *L){
        int temp = L->getPos();
        for(L->goToStart(); !L->atEnd(); L->next()){
            append(L->getElement());
        }
        L->goToPos(temp);
    }
    bool equals(List<E> *L){
        if (L->getSize() != size)
            return false;
        int tempL = L->getPos();
        Node<E> *temp = current;
        goToStart();
        for (L->goToStart(); !L->atEnd(); L->next()){
            if (L->getElement() != current->next->element){
                L->goToPos(tempL);
                current = temp;
                return false;
            }
            current = current->next;
        }
        L->goToPos(tempL);
        current = temp;
        return true;
    }

};

#endif // LINKEDLIST_H
