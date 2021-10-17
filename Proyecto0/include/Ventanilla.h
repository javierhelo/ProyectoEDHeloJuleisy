#ifndef VENTANILLA_H
#define VENTANILLA_H

#include "LinkedPriorityQueue.h"

template <typename C, typename V>
class Ventanilla{
public:
    PriorityQueue<Ventanilla<C,V>> *cola = new LinkedPriorityQueue<Ventanilla<C,V>>(2);
    C codigo;
    V subventanilla;

    Ventanilla(){}

    Ventanilla(C codigo){
        this->codigo = codigo;
    }

    Ventanilla(C codigo, V subventanilla){
        this->codigo = codigo;
        this->codigo = codigo;
    }

    void operator=(const Ventanilla& other){
        this->codigo = other.codigo;
        this->subventanilla = other.subventanilla;
    }

    bool operator==(const Ventanilla& other){
        return this->codigo == other.codigo;
    }

    bool operator!=(const Ventanilla& other){
        return this->codigo != other.codigo;
    }

    bool operator<(const Ventanilla& other){
        return this->codigo < other.codigo;
    }

    bool operator<=(const Ventanilla& other){
        return this->codigo <= other.codigo;
    }

    bool operator>(const Ventanilla& other){
        return this->codigo > other.codigo;
    }

    bool operator>=(const Ventanilla& other){
        return this->codigo >= other.codigo;
    }
};

#endif // VENTANILLA_H
