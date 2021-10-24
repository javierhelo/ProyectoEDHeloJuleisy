//Clase que implementa a List.h para poder utilizar ArrayLists
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"
#include <stdexcept>

#define DEFAULT_MAX_SIZE 1024   //durante compilación si se encuentra
                                //DEFAULT_MAX... lo sustituye por 1024

using std::runtime_error;
using std::endl;
using std::cout;

template <typename E>
class ArrayList : public List<E>{
private:
    E *elements;
    int max;
    int pos;
    int size;

    void checkCurrentElement(){
        if(size == 0)
            throw runtime_error("List is empty.");
        if(pos == size)
            throw runtime_error("No current element.");
    }
    void expand(){
        E *temp = new E[max * 2];
        for (int i = 0; i < size; i ++){
            temp[i] = elements[i];
        }
        delete [] elements;
        elements = temp;
        max *= 2;
    }

public:
    ArrayList(int max = DEFAULT_MAX_SIZE){ //nunca es buena idea poner numeros
        elements = new E[max];
        this->max = max;
        size = pos = 0; //igual que hacerlo por pasos
    }
    ~ArrayList(){
        delete [] elements;
    }

    void insert(E element){
        if(size == max)
            expand();
        for(int i = size; i > pos; i--){
            elements[i] = elements[i - 1];
        }
        elements[pos] = element;
        size++;
    }
    void append(E element){
        if(size == max)
            expand();
        elements[size] = element;
        size++;
    }
    E remove(){
        checkCurrentElement();
        E result = elements[pos];
        for(int i = pos + 1; i < size; i ++){
            elements[i - 1] = elements[i];
        }
        size--;
        return result;
    }
    void clear(){
        size = pos = 0; //borrado lógico
        delete [] elements; //asegurarse que se ejecute el
        elements = new E[max];  //destructor de los elementos
    }
    E getElement(){
        checkCurrentElement();
        return elements[pos];
    }
    void goToStart(){
        pos = 0;
    }
    void goToEnd(){
        pos = size;
    }
    void goToPos(int newPos){
        if(newPos < 0 || newPos > size){
            throw runtime_error("Position out of range.");
        }
        pos = newPos;
    }
    void next(){
        if(pos < size){
            pos++;
        }
    }
    void previous(){
        if(pos > 0){
            pos--;
        }
    }
    bool atStart(){
        return pos == 0;
    }
    bool atEnd(){
        return pos == size;
    }
    int getPos(){
        return pos;
    }
    int getSize(){
        return size;
    }
    int indexOf(E element){
        for(int i = 0; i < size; i++){
            if (elements[i] == element)
                return i;
        }
        return -1;
    }
    bool contains(E element){
        for (int i = 0; i < size; i++){
            if (elements[i] == element)
                return true;
        }
        return false;
    }
    void extend(List<E> *L){
        int temp = L->getPos();
        L->goToStart();
        while(!L->atEnd()){
            append(L->getElement());
            L->next();
        }
        L->goToPos(temp);

    }
    bool equals(List<E> *L){
        if (L->getSize() != size)
            return false;
        int temp = L->getPos();
        L->goToStart();
        for (int i = 0; i < size; i++){
            if(elements[i] != L->getElement())
                return false;
            else{
                L->next();
            }
        }
        L->goToPos(temp);
        return true;
    }
    void print(){
        int oldPos = pos;
        cout << "[";
        for (goToStart();!atEnd(); next()){
            cout << getElement() << " ";
        }
        cout << "]" << endl;
        pos = oldPos;
    }

};

#endif // ARRAYLIST_H
