//Clase de una ventanilla individual que atiende tiquete
//Autores: Javier Helo y Juleisy Porras

#ifndef VENTANILLA_H
#define VENTANILLA_H
#include "Tiquete.h"

#include <string>
using std::string;

class Ventanilla{
public:
    string codigo;
    Tiquete campo;
    int atendidos;  //atributo para llevar cuenta de tiquetes atendidos por ventanilla específica


    Ventanilla(){
        this->atendidos= 0;
    }
//    Ventanilla(string codigo){
//        this->codigo = codigo;
//    }
    Ventanilla(string codigo, Tiquete campo){
        this->codigo = codigo;
        this->campo = campo;
        this->atendidos = 0;
    }
    Ventanilla(string codigo){
        this->codigo = codigo;
        this->atendidos = 0;
    }
    ~Ventanilla(){

    }


    //Operadores de la clase
    void operator=(const Ventanilla& other){
        this->codigo = other.codigo;
        this->campo = other.campo;
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
ostream& operator << (ostream& os, const Ventanilla& p){
    os << p.codigo;
    return os;
}

#endif // VENTANILLA_H
