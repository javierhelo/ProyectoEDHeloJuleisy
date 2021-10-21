#include <iostream>
#include <locale.h>

#include "TipoVentanilla.h"

using namespace std;

int Prueba1(){
    setlocale(LC_ALL, "");
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
        //Debe mostrar los tipos de ventanillas existentes, la cantidad de ventanillas definidas para cada tipo y
        //los códigos de los tiquetes presentes en las diferentes colas.
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

int main(){
    string descripcion = "Cajas";
    string codigo = "C";
    int cantidad = 3;
    TipoVentanilla *prueba = new TipoVentanilla(descripcion, codigo, cantidad);
    prueba->printVentanilla();

    return 0;
}




