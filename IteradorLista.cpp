//
// Created by adria on 1/6/2021.
//

#include "IteradorLista.h"

template<class tipo>
IteradorLista<tipo>::IteradorLista(Nodo<tipo> *nodo) {
    this->cursor=nodo;
}

template<class tipo>
bool IteradorLista<tipo>::vacia() {
    return (cursor!=nullptr);
}

template<class tipo>
tipo IteradorLista<tipo>::proximo() {
    tipo *aux;
    if(vacia()){
        aux=cursor->getDato();
        cursor=cursor->getSiguiente();
        return aux;
    }
    return nullptr;
}

template <class tipo>
void IteradorLista<tipo>::volverInicio(Nodo<tipo> *primero) {
    cursor=primero;
}


