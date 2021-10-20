#ifndef TIPOVENTANILLA_H
#define TIPOVENTANILLA_H
#include <iostream>

#include <string>
#include "Tiquete.h"
#include "Ventanilla.h"
#include "LinkedList.h"
#include "LinkedQueue.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;


class TipoVentanilla{
public:
    string descripcion;
    string codigo;
    LinkedList<Ventanilla> *ventanillas;
    int cantidad;       //define la cantidad de ventanillas que van a haber en el atributo ventanillas
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
            Ventanilla nueva(codigo += i); // codigo += 1
            ventanillas->append(nueva);
        }
    }
    ~TipoVentanilla(){
        delete ventanillas;
        delete colaRegular;
        delete colaPreferencial;
    }

    //Setters and getters
    void setDescripcion(string descripcion){
        this->descripcion = descripcion;
    }
    string getDescripcion(){
        return descripcion;
    }
    void setCodigo(string codigo){
        this->codigo = codigo;
    }
    string getCodigo(){
        return codigo;
    }
    void setCantidadVentanillas(int cantidad){ //Se pueden poner cero ventanillas
        this->cantidad = cantidad;
        ventanillas->clear();
        for (int i = 0; i <  cantidad; i++){
            Ventanilla nueva(codigo += i); // codigo += 1
            ventanillas->append(nueva);
        }

    }
    int getCantidadVentanillas(){
        return cantidad;
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
    void operator=(const TipoVentanilla& other){
        this->codigo = other.codigo;
        this->cantidad = other.cantidad;
    }
    bool operator==(const TipoVentanilla& other){
        return this->codigo == other.codigo && this->cantidad == other.cantidad;
    }
    bool operator!=(const TipoVentanilla& other){
        return this->codigo != other.codigo && this->cantidad != other.cantidad;
    }
    bool operator<(const TipoVentanilla& other){
        return this->codigo < other.codigo && this->cantidad < other.cantidad;
    }
    bool operator<=(const TipoVentanilla& other){
        return this->codigo <= other.codigo && this->cantidad <= other.cantidad;
    }
    bool operator>(const TipoVentanilla& other){
        return this->codigo > other.codigo && this->cantidad > other.cantidad;
    }
    bool operator>=(const TipoVentanilla& other){
        return this->codigo >= other.codigo && this->cantidad >= other.cantidad;
    }


};

ostream& operator << (ostream& os, const TipoVentanilla& p){
    os << p.codigo << " " << p.cantidad << endl;
    return os;
}
#endif // TIPOVENTANILLA_H
