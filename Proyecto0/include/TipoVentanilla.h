//Clase que define los tipos de ventanillas que se pueden crear
//
#ifndef TIPOVENTANILLA_H
#define TIPOVENTANILLA_H
#include <iostream>
#include <sstream> //Biblioteca para convertir enteros a strings

#include <string>
#include "Tiquete.h"
#include "Ventanilla.h"
#include "LinkedList.h"
#include "LinkedQueue.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::stringstream;


class TipoVentanilla{
public:
    string descripcion;
    string codigo;
    LinkedList<Ventanilla> *ventanillas;
    int cantidad;       //define la cantidad de ventanillas que van a haber en el atributo ventanillas
    LinkedQueue<Tiquete> *colaRegular;
    LinkedQueue<Tiquete> *colaPreferencial;


    TipoVentanilla(){
    }
    TipoVentanilla(string descripcion, string codigo, int cantidad){
        this->descripcion = descripcion;
        this->codigo = codigo;
        this->cantidad = cantidad;
        ventanillas = new LinkedList<Ventanilla>();
        colaRegular = new LinkedQueue<Tiquete>();
        colaPreferencial = new LinkedQueue<Tiquete>();
        string codigoFalso = codigo;
        for (int i = 0; i <  cantidad; i++){
            stringstream numVentanaString;  // se declara el string donde se quiere guardar el entero
            numVentanaString << i;          // en NumVentana queda i convertido en string
            string numeroI = numVentanaString.str();
            Ventanilla nueva(codigoFalso += numeroI); // codigo += 1
            ventanillas->append(nueva);
            codigoFalso = codigo;
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

    void setCodigo(string codigo){
        this->codigo = codigo;
    }

    void setCantidadVentanillas(int cantidad){ //Se pueden poner cero ventanillas
        this->cantidad = cantidad;
        ventanillas->clear();

        string codigoFalso;
        for (int i = 0; i <  cantidad; i++){
            stringstream numVentanaString;  // se declara el string donde se quiere guardar el entero
            numVentanaString << i;          // en NumVentana queda i convertido en string
            string numeroI = numVentanaString.str();
            Ventanilla nueva(codigoFalso += numeroI); // codigo += 1
            ventanillas->append(nueva);
            codigoFalso = codigo;
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
        cout << "ventanillas: " << endl;
        ventanillas->print();
    }

    //Funcion para solicitar Tiquete
   // Tiquete* solicitarTiquete(bool preferencial){

   // }

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
