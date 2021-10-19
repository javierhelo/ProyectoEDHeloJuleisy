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


class TipoVentanilla{
private:
    string descripcion;
    string codigo;
    LinkedList<Ventanilla> *ventanillas;
    int cantidad; //hagalo una lista con todas las ventanillas
    LinkedQueue<Tiquete> *colaRegular;
    LinkedQueue<Tiquete> *colaPreferencial;

public:
    TipoVentanilla(){
    }
    TipoVentanilla(string descripcion, string codigo, int cantidad){
        this->descripcion = descripcion;
        this->codigo = codigo;
        this->cantidad = cantidad;
        ventanillas = new LinkedList<Ventanilla>();
        colaRegular = new LinkedQueue<Tiquete>();
        colaPreferencial = new LinkedQueue<Tiquete>();
        for (int i = 0; i <  cantidad; i++){
            Ventanilla nueva(descripcion, codigo, 0); // codigo += 1
            ventanillas->append(nueva);
        }
    }
    ~TipoVentanilla(){
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

ostream& operator << (ostream& os, const Ventanilla& p){
    os << p.codigo << " " << p.cantidad << endl;
    return os;
}

#endif // VENTANILLA_H
