#ifndef TIQUETE_H
#define TIQUETE_H
#include <iostream>

#include <string>
using std::string;
using std::ostream;
using std::endl;

template <typename E>
class Tiquete{
private:
    string codigo;
    bool preferencia;

public:
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
// Función para sobreescribir el funcionamiento del operador
//<< en Tiquete
template <typename E>
ostream& operator << (ostream& os, const Tiquete<E>& p){
    os << p.codigo << " " << p.preferencia << endl;
    return os;
}

#endif // TIQUETE_H
