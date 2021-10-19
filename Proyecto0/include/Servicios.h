#ifndef SERVICIOS_H
#define SERVICIOS_H

#include <string>


class Servicios{
private:
    string descripcion;
    string codigo;
    LinkedList<Servicios> *servicios;

public:
    Servicios(){}
    Servicios(string descripcion, string codigo){
        this->descripcion = descripcion;
        this->codigo = codigo;
        servicios = new LinkedList<Servicios>();
    }
    ~Servicios(){
        delete servicios;
    }


};

#endif // SERVICIOS_H
