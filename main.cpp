#include <iostream>
#include "ContenedoraListas.h"
#include "MenuAnalisis.h"

int main() {
    try {
        MenuAnalisis *ptMenu = new MenuAnalisis;
        ptMenu->menuPrincipal();
        delete ptMenu;
    }
    catch (int numError) {
        switch (numError) {
            case 1:{
                cout<<"Error: no se han cargado los datos antes de hacer un analisis"<<endl;
                return -1;
            }
            case 2: {
                cout<<"Error al abrir el archivo CadenaADN.csv"<<endl;
                return -2;
            }
            case 3: {
                cout<<"Error al abrir el archivo ListaSecuenciaEnfermedad.JSON"<<endl;
                return -3;
            }
            case 4:{
                cout<<"Error: se ha excedido el numero de errores permitido. Favor utilizar numeros para seleccionar una opcion"<<endl;
                return -4;
            }
            case 5:{
                cout<<"Error: se ha intentado generar el reporte del analisis 3 sin llevarlo a cabo anteriormente"<<endl;
                return -5;
            }
        }
    }
    return 0;
}
