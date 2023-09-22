//
// Created by adria on 31/5/2021.
//

#include "MenuAnalisis.h"

MenuAnalisis::MenuAnalisis(ContenedoraListas *contListas) {
    this->contListas=contListas;
}

MenuAnalisis::~MenuAnalisis() {
    delete contListas;
}

void MenuAnalisis::menuPrincipal() {
    int opcionM=0;
    int numErrores=0;
    while(opcionM!=4){
        cout<<"SEA BIENVENIDO AL MENU PRINCIPAL!"<<endl;
        cout<<"OPCION 1: Carga de datos"<<endl;
        cout<<"OPCION 2: Analisis de datos "<<endl;
        cout<<"OPCION 3: Generar reporte"<<endl;
        cout<<"OPCION 4: Salir"<<endl;
        cin>>opcionM;
        if(cin.fail()){
            cout<<"Utilice numeros unicamente para seleccionar una opcion"<<endl;
            menuFallo();
            numErrores+=1;
        }
        if(numErrores>3) throw 4;
        switch (opcionM) {
            case 1:{
                contListas->cargaDatos();
                cout<<"Datos cargados correctamente"<<endl;
                cout<<"Presione ENTER para continuar"<<endl;
                cin.get();
                cin.get();
                limpiaMenu();
                break;
            }
            case 2:{
                subMenuAnalisis();
                cout<<"Presione ENTER para continuar"<<endl;
                cin.get();
                cin.get();
                limpiaMenu();
                break;
            }
            case 3:{
                contListas->generarReporte();
                cout<<"Reporte generado con exito"<<endl;
                cout<<"Presione ENTER para continuar"<<endl;
                cin.get();
                limpiaMenu();
                break;
            }
            case 4:{
                cout<<"GRACIAS POR UTILIZAR NUESTROS SERVICIOS! "<<endl;
                limpiaMenu();
                break;
            }
            default:{
                cout<<"OPCION INGRESADA NO VALIDA! "<<endl;
                cout<<"Presione ENTER para continuar"<<endl;
                cin.get();
                limpiaMenu();
                break;
            }
        }
    }
    exit(0);
}

void MenuAnalisis::subMenuAnalisis() {
    int opcion;
    int numErrores=0;
    while(opcion!=4) {
        cout << "---Bienvenido al Menu de Analisis---" << endl;
        cout << "OPCION 1: ANALISIS 1 " << endl;
        cout << "OPCION 2: ANALISIS 2 " << endl;
        cout << "OPCION 3: ANALISIS 3 " << endl;
        cout << "OPCION 4: SALIR AL MENU PRINCIPAL " << endl;
        cin >> opcion;
        if(cin.fail()){
            cout<<"Utilice numeros unicamente para seleccionar una opcion"<<endl;
            menuFallo();
            numErrores+=1;
        }
        if(numErrores>3) throw 4;
        switch (opcion) {
            case 1: {
                auto inicio = std::chrono::high_resolution_clock::now();
                contListas->analisis1();
                auto fin = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duracion = fin - inicio;
                double seconds = duracion.count();
                contListas->imprimirAnalisis1(to_string(seconds));
                cout << "Presione ENTER para continuar" << endl;
                cin.get();
                cin.get();
                limpiaMenu();
                break;
            }
            case 2: {
                cout << contListas->analisis2();
                cout << "Presione ENTER para continuar" << endl;
                cin.get();
                cin.get();
                limpiaMenu();
                break;
            }
            case 3: {
                cout << contListas->analisis3();
                cout << "Presione ENTER para continuar" << endl;
                cin.get();
                cin.get();
                limpiaMenu();
                break;
            }
            case 4: {
                cout << "VOLVIENDO AL MENU PRINCIPAL! " << endl;
                limpiaMenu();
                break;
            }
            default: {
                cout << "LA OPCION SELECCIONADA NO EXISTE" << endl;
                cout << "Presione ENTER para continuar" << endl;
                cin.get();
                cin.get();
                limpiaMenu();
                break;
            }
        }
    }
}

void MenuAnalisis::limpiaMenu() {
    sleep(1);
    cout << string(50, '\n');
}

void MenuAnalisis::menuFallo() {
    cin.clear();
    cin.ignore(10000, '\n');
    limpiaMenu();
}
