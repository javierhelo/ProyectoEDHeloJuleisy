//Clase que define un tiquete para que el usuario pueda ser atendido
//Autores: Javier Helo y Juleisy Porras

#ifndef TIQUETE_H
#define TIQUETE_H
#include <iostream>

#include <string>
using std::string;
using std::ostream;
using std::endl;

class Tiquete{
public:
    string codigo;
    bool preferencia;

    Tiquete(){
    }
    Tiquete(string codigo, bool preferencia){
        this->codigo = codigo;
        this->preferencia = preferencia;
    }
    ~Tiquete(){
    }

    void operator=(const Tiquete& other){
        this->codigo = other.codigo;
    }
    bool operator==(const Tiquete& other){
        return this->codigo == other.codigo;
    }
    bool operator!=(const Tiquete& other){
        return this->codigo != other.codigo;
    }
    bool operator<(const Tiquete& other){
        return this->codigo < other.codigo;
    }
    bool operator<=(const Tiquete& other){
        return this->codigo <= other.codigo;
    }
    bool operator>(const Tiquete& other){
        return this->codigo > other.codigo;
    }
    bool operator>=(const Tiquete& other){
        return this->codigo >= other.codigo;
    }



};
// Funci�n para sobreescribir el funcionamiento del operador
//<< en Tiquete
ostream& operator << (ostream& os, const Tiquete& p){
    os << p.codigo;
    return os;
}

#endif // TIQUETE_H
