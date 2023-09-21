//
// Created by adria on 19/5/2021.
//

#ifndef PROYECTO2_NODO_H
#define PROYECTO2_NODO_H
#include <iostream>

using namespace std;
template<class tipo>

class Nodo {
private:
    tipo *dato;
    Nodo *siguiente;
public:
    Nodo(){
        dato= nullptr;
        siguiente= nullptr;
    }

    tipo *getDato() const {
        return dato;
    }

    void setDato(tipo *dato) {
        Nodo::dato = dato;
    }

    Nodo *getSiguiente() const {
        return siguiente;
    }

    void setSiguiente(Nodo *siguiente) {
        Nodo::siguiente = siguiente;
    }

    string toStringDato(){
        return getDato()->toString();
    }

    string cadADNDato(){
        return getDato()->getAdn();
    }

    int enfermedadesDato(){
        return getDato()->getEnfermedades();
    }
};
#endif //PROYECTO2_NODO_H
