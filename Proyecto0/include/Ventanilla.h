#ifndef VENTANILLA_H
#define VENTANILLA_H
#include "Tiquete.h"

#include <string>
using std::string;

class Ventanilla{
public:
    string codigo;
    Tiquete *campo;


    Ventanilla(){}
//    Ventanilla(string codigo){
//        this->codigo = codigo;
//    }
    Ventanilla(string codigo, Tiquete *campo = nullptr){
        this->codigo = codigo;
        this->campo = campo;
    }
    ~Ventanilla(){

    }
    void setCodigo(string codigo){
        this->codigo = codigo;
    }
    void setCampo(Tiquete *nuevoTiquet){ //Seria atender?
        campo = nuevoTiquet;
    }
    Tiquete* getCampo(){
        return campo;
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
