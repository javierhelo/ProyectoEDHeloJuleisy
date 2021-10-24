//Clase que define los tipos de ventanillas que se pueden crear
//Autores: Javier Helo y Juleisy Porras

#ifndef TIPOVENTANILLA_H
#define TIPOVENTANILLA_H
#include <iostream>
#include <sstream> //Biblioteca para convertir enteros a strings
#include <time.h>

#include <string>
#include "Tiquete.h"
#include "Ventanilla.h"
#include "LinkedList.h"
#include "LinkedQueue.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;


class TipoVentanilla{
public:
    string descripcion;
    string codigo;
    List<Ventanilla> *ventanillas;
    int cantidad;                       //define la cantidad de ventanillas que van a haber en el atributo ventanillas
    Queue<Tiquete> *colaRegular;
    Queue<Tiquete> *colaPreferencial;
    int numeroTiquete = 0;              //variable para saber por que numero de tiquete va la ventanilla
    int solicitadosPreferenciales = 0;  //llevar cuenta de cuantos tiquetes preferenciales se solicitan
    long tiempoEspera;                  //suma de tiempos de espera en que fue atendido cada tiquete
    time_t inicio;                      //variable tipo time que indica el inicio del lapso de tiempo
    time_t final;                       //variable tipo time que indica el final del lapso de tiempo
    long atendidosTipoVentanilla = 0;    //atributo para llevar cuenta de tiquetes atendidos por tipo de ventanilla
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
            string numero = to_string(i);
            Ventanilla nueva(codigo + numero); // codigo += 1
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

    void setCodigo(string codigo){
        this->codigo = codigo;
    }

    void setCantidadVentanillas(int cantidad){ //Se pueden poner cero ventanillas
        this->cantidad = cantidad;
        ventanillas->clear();
        for (int i = 0; i <  cantidad; i++){
            string numero = to_string(i);
            Ventanilla nueva(codigo + numero); // codigo += 1
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
        cout << "ventanillas: ";
        ventanillas->print();
    }

    //Funcion para solicitar Tiquete
    string solicitarTiquete(bool preferencia){
        string numero = to_string(numeroTiquete);
        string codigoTiquete = codigo + numero;
        if (preferencia){
            Tiquete nuevo(codigoTiquete, true);
            colaPreferencial->enqueue(nuevo);
            time(&inicio);
            numeroTiquete++;
            solicitadosPreferenciales++;
            return codigoTiquete;
        }
        Tiquete nuevo(codigo + numero, false);
        colaRegular->enqueue(nuevo);
        time(&inicio);
        numeroTiquete++;
        return codigoTiquete;
    }

    //Función que atiende en una ventanilla determinada
    string atender(int numeroVentanilla){
        ventanillas->goToPos(numeroVentanilla);
        Ventanilla actual = ventanillas->getElement();
        if (colaPreferencial->getSize() != 0){
            Tiquete aAtender = colaPreferencial->dequeue();
            time(&final);
            tiempoEspera += difftime(final,inicio);
            actual.campo = aAtender;
            actual.atendidos++;        //llevar cuenta de tiquetes atendidos por ventanilla específica
            atendidosTipoVentanilla++; //llevar cuenta de tiquetes atendidos por tipo de ventanilla
            return "Se está atendiendo un tiquete preferencial. \n";
        }else if (colaRegular->getSize() != 0){
            Tiquete aAtender = colaRegular->dequeue();
            time(&final);
            tiempoEspera += difftime(final,inicio);
            actual.campo = aAtender;
            actual.atendidos++;     //llevar cuenta de tiquetes atendidos por ventanilla específica
            atendidosTipoVentanilla++; //llevar cuenta de tiquetes atendidos por tipo de ventanilla
            return "Se está atendiendo un tiquete. \n";
        }
        return "No hay tiquetes en la cola. \n";
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
