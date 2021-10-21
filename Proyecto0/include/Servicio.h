#ifndef SERVICIO_H
#define SERVICIO_H

#include "ArrayList.h"

#include <string>
#include <stdexcept>

using std::runtime_error;


class Servicio{
public:
    string descripcion;
    string codigo;
    ArrayList<Servicio> *listaServicios;

    Servicio(){}
    Servicio(string descripcion, string codigo){
        this->descripcion = descripcion;
        this->codigo = codigo;
        listaServicios = new ArrayList<Servicio>();
    }
    ~Servicio(){
        delete servicios;
    }

    void agregarServicio(string descripcion, string codigo){
        Servicio *nuevo = new Servicio(descripcion, codigo);
        listaServicios->append(nuevo);
    }

    void eliminarServicio(int pos){
        if (pos < 0 || pos > listaServicios->size){
            throw runtime_error("Seleccione una posicion valida en la lista de servicios.");
        }
        listaServicios->goToPos(pos);
        listaServicios->remove();
    }

    void reordenar(int posActual, int posDestino){
        if (posActual < 0 || posActual > listaServicios->size){
            throw runtime_error("Seleccione una posicion valida en la lista de servicios.");
        }
        if (posDestino < 0 || posDestino > listaServicios->size){
            throw runtime_error("Seleccione una posicion valida en la lista de servicios.");
        }
        listaServicios->goToPos(posActual);
        Servicio eliminado = listaServicios->remove();
        listaServicios->goToPos(posDestino);
        listaServicios->insert(eliminado);
    }





};

#endif // SERVICIO_H
