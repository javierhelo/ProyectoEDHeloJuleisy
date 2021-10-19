#ifndef VENTANILLA_H
#define VENTANILLA_H
#include <iostream>

#include <string>
#include "Tiquete.h"

#include "LinkedList.h"
#include "LinkedQueue.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

template <typename E>
class Ventanilla{
private:
    string descripcion;
    string codigo;
    LinkedList<Ventanilla> *ventanillas = new LinkedList<Ventanilla>();
    int cantidad; //hagalo una lista con todas las ventanillas
    LinkedQueue<Tiquete<E>> *colaRegular = new LinkedQueue<Tiquete<E>>();
    LinkedQueue<Tiquete<E>> *colaPreferencial = new LinkedQueue<Tiquete<E>>();

public:
    Ventanilla(){
    }
    Ventanilla(string descripcion, string codigo, int cantidad){
        this->descripcion = descripcion;
        this->codigo = codigo;
        this->cantidad = cantidad;
        for (int i = 0; i <  cantidad; i++){
            Ventanilla *nueva = new Ventanilla(descripcion, codigo, 0); // codigo += 1
            ventanillas->append(nueva);
        }
    }
    ~Ventanilla(){
        delete ventanillas;
        delete colaRegular;
        delete colaPreferencial;
    }
    void printVentanilla(){
        cout << descripcion << "-" << codigo << "-" << cantidad << endl;
        cout << "cola regular: ";
        colaRegular->print();
        cout << "cola preferencial: ";
        colaPreferencial->print();
        cout << "ventanillas: " ;
        ventanillas->print();
    }
    void operator=(const Ventanilla& other){
        this->codigo = other.codigo;
        this->cantidad = other.cantidad;
    }
    bool operator==(const Ventanilla& other){
        return this->codigo == other.codigo && this->cantidad == other.cantidad;
    }
    bool operator!=(const Ventanilla& other){
        return this->codigo != other.codigo && this->cantidad != other.cantidad;
    }
    bool operator<(const Ventanilla& other){
        return this->codigo < other.codigo && this->cantidad < other.cantidad;
    }
    bool operator<=(const Ventanilla& other){
        return this->codigo <= other.codigo && this->cantidad <= other.cantidad;
    }
    bool operator>(const Ventanilla& other){
        return this->codigo > other.codigo && this->cantidad > other.cantidad;
    }
    bool operator>=(const Ventanilla& other){
        return this->codigo >= other.codigo && this->cantidad >= other.cantidad;
    }


};
template <typename E>
ostream& operator << (ostream& os, const Ventanilla<E>& p){
    os << p.codigo << " " << p.cantidad << endl;
    return os;
}

#endif // VENTANILLA_H
