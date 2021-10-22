#ifndef SERVICIO_H
#define SERVICIO_H

#include "ArrayList.h"

#include <string>
#include <stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;


class Servicio{
public:
    string descripcion;
    string codigo;
//    List<Servicio> *listaServicios = new ArrayList<Servicio>();

    Servicio(){
    }

    Servicio(string descripcion, string codigo){
        this->descripcion = descripcion;
        this->codigo = codigo;
    }
    ~Servicio(){
//        delete listaServicios;
    }
    void printServicio(){
        cout << descripcion << " - " << codigo << endl;
    }

//    void agregarServicio(string descripcion, string codigo){
//        Servicio nuevo(descripcion, codigo);
//        listaServicios->append(nuevo);
//    }
//
//    void eliminarServicio(int pos){
//        if (pos < 0 || pos > listaServicios->getSize()){
//            throw runtime_error("Seleccione una posicion valida en la lista de servicios.");
//        }
//        listaServicios->goToPos(pos);
//        listaServicios->remove();
//    }

    //Función para reordenar servicios
    void reordenar(int posActual, int posDestino, List<Servicio*> *listaServicios){
        if (posActual < 0 || posActual > listaServicios->getSize()){
            throw runtime_error("Seleccione una posicion valida en la lista de servicios.");
        }
        if (posDestino < 0 || posDestino > listaServicios->getSize()){
            throw runtime_error("Seleccione una posicion valida en la lista de servicios.");
        }
        listaServicios->goToPos(posActual);
        Servicio *eliminado = listaServicios->remove();

        listaServicios->goToPos(posDestino);
        listaServicios->insert(eliminado);
    }
//
//    void printS(){
//        cout << "Servicios disponibles: " << endl;
//        for (int i = 0; i < listaServicios->getSize(); i++){
//            listaServicios->goToPos(i);
//            Servicio actual = listaServicios->getElement();
//            cout << i << " - " << actual.descripcion << endl;
//        }
//    }

    void operator=(const Servicio& other){
        this->descripcion = other.descripcion;
        this->codigo = other.codigo;
//        this->listaServicios = other.listaServicios;
    }
    bool operator==(const Servicio& other){
        return this->codigo == other.codigo && this->descripcion == other.descripcion;
    }
    bool operator!=(const Servicio& other){
        return this->codigo != other.codigo && this->descripcion!= other.descripcion;
    }
    bool operator<(const Servicio& other){
        return this->codigo < other.codigo && this->descripcion < other.descripcion;
    }
    bool operator<=(const Servicio& other){
        return this->codigo <= other.codigo && this->descripcion <= other.descripcion;
    }
    bool operator>(const Servicio& other){
        return this->codigo > other.codigo && this->descripcion > other.descripcion;
    }
    bool operator>=(const Servicio& other){
        return this->codigo >= other.codigo && this->descripcion >= other.descripcion;
    }

};

ostream& operator << (ostream& os, const Servicio& p){
    os << p.codigo << " " << p.descripcion << endl;
    return os;
}


#endif // SERVICIO_H
