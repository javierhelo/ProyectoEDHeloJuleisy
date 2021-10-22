#include <iostream>
#include <locale.h>

#include "TipoVentanilla.h"
#include "Servicio.h"
#include "Tiquete.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "");

    //lista para llevar control de todos los tipos de ventanillas
    ArrayList<TipoVentanilla> *totalVentanillas = new ArrayList<TipoVentanilla>();

    //Creando tipos de ventanillas arbitrarias
    string descripcion1 = "Cajas";
    string codigo1 = "C";
    int cantidad1 = 4;

    string descripcion2 = "Servicio al cliente";
    string codigo2 = "S";
    int cantidad2 = 6;

    string descripcion3 = "Información";
    string codigo3 = "I";
    int cantidad3 = 3;

    TipoVentanilla cajas(descripcion1, codigo1, cantidad1);
    TipoVentanilla servicioCliente(descripcion2, codigo2, cantidad2);
    TipoVentanilla informacion(descripcion3, codigo3, cantidad3);

    totalVentanillas->append(cajas);
    totalVentanillas->append(servicioCliente);
    totalVentanillas->append(informacion);

    cout << "Probando 1..." << endl;

    //Agregando serivicios disponibles
    Servicio *serviciosDisponibles = new Servicio("", "");

    cout << "2..." << endl;

    serviciosDisponibles->agregarServicio("Depósito", "C");
    serviciosDisponibles->agregarServicio("Retiro", "C");
    serviciosDisponibles->agregarServicio("Solicitar tarjeta", "S");
    serviciosDisponibles->agregarServicio("Pagar recibo", "C");
    serviciosDisponibles->agregarServicio("Estado de cuenta", "I");
    serviciosDisponibles->agregarServicio("Pagar marchamo", "C");
    serviciosDisponibles->agregarServicio("Cancelar tarjeta", "S");
    serviciosDisponibles->agregarServicio("Cambio de colones a dólares", "C");
    serviciosDisponibles->agregarServicio("Cambio de dólares a colones", "C");
    serviciosDisponibles->agregarServicio("Retirar marchamo", "I");

    cout << "3..." << endl;

    serviciosDisponibles->printS();

    cout << "Bienvenido al sistema de administración de colas: "<< endl;
    cout << "1. Ver estado de las colas" << endl;
    cout << "2. Solicitar tiquete" << endl;
    cout << "3. Atender" << endl;
    cout << "4. Administración" << endl;
    cout << "5. Estadísticas del sistema" << endl;
    cout << "6. Salir" << endl;
    cout << "Escriba el número del proceso que desea realizar: " ;
    int n;
    cin >> n;
    switch(n){
    case 1:
        cajas.printVentanilla();
        servicioCliente.printVentanilla();
        informacion.printVentanilla();


        break;

    case 2:
        cout << "a. Seleccionar servicio" << endl;
        cout << "b. Cliente preferencial" << endl;
        cout << "c. Regresar" << endl;
        cout << "Escoja una opción: ";
        char seleccion;
        cin >> seleccion;
        break;
    case 3:
        //Solicitar tipo de ventanilla y numero para buscar en las colas
        //el siguiente tiquete a atender, lo borra y lo atiende actualmente.
        break;
    case 4:
        cout << "a. Definir tipos de ventanillas" << endl;
        cout << "b. Definir servicios disponibles" << endl;
        cout << "Escoja una opción: ";
        cin >> seleccion;
        switch(seleccion){
        case 'a':
            cout << "1. Agregar" << endl;
            cout << "2. Eliminar" << endl;
            cout << "Elija su opción: ";
            int opcion;
            cin >> opcion;
            while (opcion < 1 || opcion > 2){
                cout << "Indique alguna de las opciones con el número correspondiente: ";
                cin >> opcion;
            }
            if (opcion == 1){ //Agregar nuevo tipo de ventanillas con descripcion codigo y cantidad

            }else { //Eliminar tipo de ventanillas y todas las ventanillas definidas

            }
            break;
        case 'b':
            cout << "1. Agregar un servicio" << endl;
            cout << "2. Eliminar un servicio" << endl;
            cout << "3. Reordenar elementos en la lista.";
            cout << "1. Agregar" << endl;
            cout << "2. Eliminar" << endl;
            cout << "3. Reordenar";
            cout << "Elija su opción: ";
            cin >> opcion;
            while (opcion < 1 || opcion > 3){
                cout << "Indique alguna de las opciones con el número correspondiente: ";
                cin >> opcion;
            }
            if (opcion == 1){
                //Agregar un nuevo tipo de servicio
            }else if (opcion == 2){
                //Eliminar un tipo de servicio
            }else{
                //Reordenar elementos en la lista de servicios
            }

            break;
        }
        break;
    case 5:
        //Tiempo promedio de espera por tipo de ventanilla
        //Total de tiquetes dispensados por tipo de ventanilla
        //Total de tiquetes atendidos por ventanilla
        //Total de tiquetes dispensados por tipo de transacción
        //Total de tiquetes preferenciales dispensados en todo el sistema
    case 6:
        return 0;
    }

        return 0;
}






