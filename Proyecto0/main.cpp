#include <iostream>
#include <locale.h>

#include "TipoVentanilla.h"
#include "Servicio.h"
#include "Tiquete.h"

using namespace std;
//Función que imprime los tipos de ventanillas de una lista
void imprimirTotalVentanillas(List<TipoVentanilla*> *totalVentanillas){
    int i = 0;
    for(totalVentanillas->goToStart(); !totalVentanillas->atEnd(); totalVentanillas->next()){
            cout << i << "- ";
            TipoVentanilla *actual = totalVentanillas->getElement();
            actual->printVentanilla();
            cout << endl;
            i++;
        }
}
//Función que imprime los tipos de servicios de una lista con estos
void imprimirTotalServicios(List<Servicio*> *totalServicios){
    int i = 0;
    for(totalServicios->goToStart(); !totalServicios->atEnd(); totalServicios->next()){
            cout << i << "- ";
            Servicio *actual = totalServicios->getElement();
            actual->printServicio();
            i++;
        }
}


int main(){
    setlocale(LC_ALL, "");

    //listas para llevar control de todos los Tipos de Ventanillas y Servicios
    List<TipoVentanilla*> *totalVentanillas = new LinkedList<TipoVentanilla*>();
    List<Servicio*> *totalServicios = new LinkedList<Servicio*>();

    //Creando tipos de ventanillas arbitrarias y agregandolas a la lista de totalVentanillas
    string descripcion1 = "Cajas";
    string codigo1 = "C";
    int cantidad1 = 4;

    string descripcion2 = "Servicio al cliente";
    string codigo2 = "S";
    int cantidad2 = 6;

    string descripcion3 = "Información";
    string codigo3 = "I";
    int cantidad3 = 3;

    //Crearlas
    TipoVentanilla *caja = new TipoVentanilla(descripcion1, codigo1, cantidad1);
    TipoVentanilla *servicioCliente = new TipoVentanilla(descripcion2, codigo2, cantidad2);
    TipoVentanilla *informacion = new TipoVentanilla(descripcion3, codigo3, cantidad3);

    //Agregarlas
    totalVentanillas->append(caja);
    totalVentanillas->append(servicioCliente);
    totalVentanillas->append(informacion);



    //Agregando servicios disponibles
    string ddeposito = "deposito";
    string cdeposito = "C";

    Servicio *deposito = new Servicio(ddeposito, cdeposito);
    Servicio *retiro = new Servicio("Retiro", "C");
    Servicio *cambio = new Servicio("Cambio de dólares a colones", "C");
    Servicio *cambio2 = new Servicio("Cambio de colones a dólares", "C");
    Servicio *tarjeta = new Servicio("Solicitar tarjeta", "S");
    Servicio *cancelartarjeta = new Servicio("Cancelar tarjeta", "S");
    Servicio *cuenta = new Servicio("Estado de cuenta", "I");
    Servicio *marchamo = new Servicio("Retirar marchamo", "I");


    totalServicios->append(deposito);
    totalServicios->append(retiro);
    totalServicios->append(cambio);
    totalServicios->append(cambio2);
    totalServicios->append(tarjeta);
    totalServicios->append(cancelartarjeta);
    totalServicios->append(cuenta);
    totalServicios->append(marchamo);

    //MENU PRINCIPAL

    int tiquetesPreferenciales = 0;     //Contador de tiquetes preferenciales
    bool seguirDentro = true;
    while (seguirDentro){
    bool regresar = false;     //Variable para poder utilizar la opción de regresar al menú principal
    cout << "Bienvenido al sistema de administración de colas: "<< endl;
    cout << "1. Ver estado de las colas" << endl;
    cout << "2. Solicitar tiquete" << endl;
    cout << "3. Atender" << endl;
    cout << "4. Administración" << endl;
    cout << "5. Estadísticas del sistema" << endl;
    cout << "6. Salir" << endl;
    cout << "Escriba el número del proceso que desea realizar: " ;
    int n;      //Chequear que sea un entero (PROOOFEEEEEEE ) "meter un string"
    cin >> n;
    while (n < 1 || n > 6){
        cout << "El número ingresado no está en las opciones, elija de nuevo que gusta hacer: ";
        cin >> n;
    }
    switch(n){
    case 1:         // Mostrar tipos de ventanillas
        imprimirTotalVentanillas(totalVentanillas);
        break;

    case 2:         //Solicitar Tiquete
        cout << "a. Seleccionar servicio" << endl;
        cout << "b. Cliente preferencial" << endl;
        cout << "c. Regresar" << endl;
        cout << "Escoja una opción: ";
        char seleccion;
        cin >> seleccion;
        while (seleccion != 'a' && seleccion != 'b' && seleccion != 'c'){
            cout << "Escoja una opción válida (a, b, c): ";
            cin >> seleccion;
        }
        switch(seleccion){
        case 'a':               //El usuario elige un servicio y el sistema lo pone en la cola correspondiente
            {
            imprimirTotalServicios(totalServicios);
            cout << "Seleccione el número de servicio que desea utilizar: ";
            int numServicio;
            cin >> numServicio;
            while (numServicio < 0 || numServicio > totalServicios->getSize() - 1){
                cout << "El número seleccionado no está enumerado en la lista de servicios. Seleccione de nuevo: ";
                cin >> numServicio;
            }
            totalServicios->goToPos(numServicio);
            Servicio *aSolicitar = totalServicios->getElement();
            aSolicitar->tiquetesSolicitados++;          //llevar estadísticas de los tiquetes;
            bool encontrado = false;
            for (totalVentanillas->goToStart(); !totalVentanillas->atEnd(); totalVentanillas->next()){
                TipoVentanilla *actual = totalVentanillas->getElement();
                if (actual->codigo == aSolicitar->codigo){
                    encontrado = true;
                    cout << "Su tiquete es: " << actual->solicitarTiquete(false);
                }
            }
            if (!encontrado){
                cout << "El código de su servicio no está relacionado con ningún tipo de ventanilla.";
            }
            break;
        }
        case 'b':               //Se coloca como cliente preferencial para el servicio que seleccione
        {                       //Se rodea con un bloque de corchetes para poder declarar una variable nueva en el case
            imprimirTotalServicios(totalServicios);
            cout << "Seleccione el número de servicio que desea utilizar: ";
            int numServicio;
            cin >> numServicio;
            while (numServicio < 0 || numServicio > totalServicios->getSize() - 1){
                cout << "El número seleccionado no está enumerado en la lista de servicios. Seleccione de nuevo: ";
                cin >> numServicio;
            }
            totalServicios->goToPos(numServicio);
            Servicio *aSolicitar = totalServicios->getElement();
            aSolicitar->tiquetesSolicitados++;
            bool encontrado = false;
            for (totalVentanillas->goToStart(); !totalVentanillas->atEnd(); totalVentanillas->next()){
                TipoVentanilla *actual = totalVentanillas->getElement();
                if (actual->codigo == aSolicitar->codigo){
                    encontrado = true;
                    cout << "Su tiquete es: " << actual->solicitarTiquete(true);   //Estadísticas
                    tiquetesPreferenciales++;
                }
            }
            if (!encontrado){
                cout << "El código de su servicio no está relacionado con ningún tipo de ventanilla.";
            }
            break;
        }

        case 'c':               //Regresa al menú principal
            regresar = true;
            break;
        }
        break;

    case 3:                 //Solicitar tipo de ventanilla y numero para buscar en las colas
                            //el siguiente tiquete a atender, lo borra y lo atiende actualmente.
        {
        cout << "Escriba el codigo del tipo de ventanilla atenderá el siguiente Tiquete: ";
        string codigoAtender;
        cin >> codigoAtender;
        bool estaVentanilla = false;    //valor para saber si el código que ingreso el usuario es correcto
        TipoVentanilla *tipoVentanillaAtiende;
        for (totalVentanillas->goToStart(); !totalVentanillas->atEnd(); totalVentanillas->next()){
            TipoVentanilla *actual = totalVentanillas->getElement();
            if (actual->codigo == codigoAtender){
                estaVentanilla = true;
                tipoVentanillaAtiende = actual;       //guardando en que tipo de ventanilla se atenderá
            }
        }
        if (!estaVentanilla){
            cout << "El codigo de tipo de ventanilla que escribió no fue encontrado";
            break;
        }
        cout << "Escriba el numero de la ventanilla que lo va a atender: ";
        int numeroVentanilla;
        cin >> numeroVentanilla;
        while (numeroVentanilla < 0 || numeroVentanilla > tipoVentanillaAtiende->ventanillas->getSize() - 1){
            cout << "Seleccione un número de ventanilla existente: ";
            cin >> numeroVentanilla;
        }
        cout << tipoVentanillaAtiende->atender(numeroVentanilla);
        break;
        }
    case 4:
        cout << "a. Definir tipos de ventanillas" << endl;
        cout << "b. Definir servicios disponibles" << endl;
        cout << "Escoja una opción: ";
        cin >> seleccion;
        while (seleccion != 'a' && seleccion != 'b'){
            cout << "Escoja una opción válida: ";
            cin >> seleccion;
        }

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
                    cout << "Escriba la descripción de la nueva ventanilla: ";
                    string descripcionVentanilla;
                    cin >> descripcionVentanilla;
                    cout << "Escriba el código de la nueva ventanilla: ";
                    string codigoVentanilla;
                    cin >> codigoVentanilla;
                    cout << "Escriba la cantidad de ventanillas deseada: ";
                    int cantida;
                    cin >> cantida;
                    while (cantida < 1){
                        cout << "Escriba la cantidad de ventanillas deseada (entero positivo): ";
                        cin >> cantida;
                    }
                    TipoVentanilla *nueva = new TipoVentanilla(descripcionVentanilla, codigoVentanilla, cantida);
                    totalVentanillas->append(nueva);
            }else { //Eliminar tipo de ventanillas y todas las ventanillas definidas
                    imprimirTotalVentanillas(totalVentanillas);
                    cout << "Ingrese el número de la Ventanilla que desea eliminar: ";
                    cin >> opcion;
                    while(opcion < 0 || opcion > totalVentanillas->getSize() - 1){
                        cout << "Ingrese el número correcto de la Ventanilla que desea eliminar: ";
                        cin >> opcion;
                    }
                    totalVentanillas->goToPos(opcion); //Eliminando el tipo de ventanilla
                    TipoVentanilla *esta = totalVentanillas->remove();
                    delete esta;
            }
            break;
        case 'b':
            cout << "1. Agregar un servicio" << endl;
            cout << "2. Eliminar un servicio" << endl;
            cout << "3. Reordenar elementos en la lista" << endl;
            cout << "Elija su opción: ";
            cin >> opcion;
            while (opcion < 1 || opcion > 3){
                cout << "Indique alguna de las opciones con el número correspondiente: ";
                cin >> opcion;
            }
            if (opcion == 1){
                //Agregar un nuevo tipo de servicio con descripción y código
                    cout << "Escriba la descripción del nuevo servicio: ";
                    string descripcionServicio;
                    cin >> descripcionServicio;
                    cout << "Escriba el código del nuevo servicio: ";
                    string codigoServicio;
                    cin >> codigoServicio;
                    Servicio *nuevo = new Servicio(descripcionServicio, codigoServicio);
                    totalServicios->append(nuevo);

            }else if (opcion == 2){
                //Eliminar un tipo de servicio
                imprimirTotalServicios(totalServicios);
                cout << "Ingrese el número del servicio que desea eliminar: ";
                cin >> opcion;
                while(opcion < 0 || opcion > totalServicios->getSize() - 1){
                    cout << "Ingrese el número correcto del Servicio que desea eliminar: ";
                    cin >> opcion;
                }
                totalServicios->goToPos(opcion); //Eliminando el tipo de ventanilla
                Servicio *esta = totalServicios->remove();
                delete esta;
            }else{
                //Reordenar elementos en la lista de servicios
                imprimirTotalServicios(totalServicios);
                cout << "Indique que numero de Servicio desea reordenar: ";
                cin >> opcion;
                cout << "Indique la posición en la que desea que quede este servicio: ";
                int posDestino;
                cin >> posDestino;
                totalServicios->goToStart();
                Servicio *actual = totalServicios->getElement();
                actual->reordenar(opcion, posDestino, totalServicios);
            }
            break;
        }
        break;
    case 5:     //Estadísticas del sistema
        {
        cout << "a. Tiempo promedio de espera por tipo de ventanilla. " << endl;
        cout << "b. Total de tiquetes dispensados por tipo de ventanilla. " << endl;
        cout << "c. Total de tiquetes atendidos por ventanilla. " << endl;
        cout << "d. Total de tiquetes dispensados por tipo de transacción. " << endl;
        cout << "e. Total de tiquetes preferenciales dispensados en todo el sistema. " << endl;
        char letra;
        cin >> letra;
        while (letra != 'a' && letra != 'b' && letra != 'c' && letra != 'd' && letra != 'e'){
            cout << "Seleccione alguna de las opciones especificadas: ";
            cin >> letra;
        }
        switch(letra){
        case 'a':       //Tiempo promedio de espera por tipo de ventanilla.

            break;
        case 'b':       //Total de tiquetes dispensados por tipo de ventanilla.
            for (totalVentanillas->goToStart(); !totalVentanillas->atEnd(); totalVentanillas->next()){
                TipoVentanilla *actual = totalVentanillas->getElement();
                cout << "Total de Tiquetes de " << actual->descripcion << ": " << actual->numeroTiquete << endl;
            }
            break;
        case 'c':       //Total de tiquetes atendidos por ventanilla.
            for (totalVentanillas->goToStart(); !totalVentanillas->atEnd(); totalVentanillas->next()){
                TipoVentanilla *actual = totalVentanillas->getElement();
                cout << actual->descripcion << ":" << endl;
                List<Ventanilla> *listaVentanillas = actual->ventanillas;
                for (listaVentanillas->goToStart(); !listaVentanillas->atEnd(); listaVentanillas->next()){
                    Ventanilla ventanillaActual = listaVentanillas->getElement();
                    cout << ventanillaActual.codigo << "->" << ventanillaActual.atendidos << " ";
                }
                cout << endl;
            }
            break;
        case 'd':       //Total de tiquetes dispensados por tipo de transacción.
            for (totalServicios->goToStart(); !totalServicios->atEnd(); totalServicios->next()){
                Servicio *actual = totalServicios->getElement();
                cout << actual->descripcion << "->" << actual->tiquetesSolicitados << endl;
            }
            break;
        case 'e':       //Total de tiquetes preferenciales dispensados en todo el sistema.
            {
            int i = 0;
            for (totalVentanillas->goToStart(); !totalVentanillas->atEnd(); totalVentanillas->next()){
                TipoVentanilla *actual = totalVentanillas->getElement();
                i += actual->solicitadosPreferenciales;
            }
            cout << "El total de tiquetes preferenciales omitidos es de : " << i << endl;
            break;
            }

        }
        break;
        }
    case 6:
        return 0;
    }
    //Elección para decidir si el usuario se quiere salir o no
    if (regresar == false){
        cout << "¿Desea realizar algún otro trámite? (0 = no, 1 = sí): ";
        int laDecision;
        cin >> laDecision;
        while (laDecision < 0 || laDecision > 1){
            cout << "Debe ingresar alguna de las opciones indicadas." << endl;
            cout << "¿Desea realizar algún otro trámite? (0 = no, 1 = sí): ";
            cin >> laDecision;
        }
        if (laDecision == 0){
            seguirDentro = false;
            cout << "Gracias por visitar el Programa de administración de colas hecho por Juleisy y Javier." << endl;
        }
    }
    }
        return 0;
}






