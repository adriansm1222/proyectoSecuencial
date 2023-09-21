//
// Created by adria on 19/5/2021.
//

#include "Lista.h"
template<class tipo>
Lista<tipo>::Lista() {
    raiz = new Nodo<tipo>;
}

template<class tipo>
Lista<tipo>::~Lista() {
    Nodo<tipo> *temp;
    Nodo<tipo> *anterior;
    if(raiz->getSiguiente()== nullptr){
        delete raiz;
    }else{
        while (raiz->getSiguiente()!= nullptr){
            temp=raiz;
            while (temp->getSiguiente()!= nullptr){
                anterior=temp;
                temp=temp->getSiguiente();
            }
            anterior->setSiguiente(nullptr);
            delete temp;
        }
    }
}

template<class tipo>
bool Lista<tipo>::listaVacia() {
    if(raiz->getSiguiente()==nullptr){
        return true;
    }
    return false;
}

template<class tipo>
void Lista<tipo>::ingresar(tipo *dato) {
    Nodo<tipo> *nodoNuevo= new Nodo<tipo>;
    nodoNuevo->setDato(dato);
    nodoNuevo->setSiguiente(raiz->getSiguiente());
    raiz->setSiguiente(nodoNuevo);
}

template<class tipo>
string Lista<tipo>::toString() {
    stringstream s;
    Nodo<tipo> *temp=new Nodo<tipo>;
    if(listaVacia()){
        s<<"Lista vacia"<<endl;
    }else{
        temp=raiz->getSiguiente();
        while (temp!= nullptr){
            s<<temp->toStringDato();
            temp=temp->getSiguiente();
        }
    }
    return s.str();
}

template<class tipo>
IteradorLista<tipo> * Lista<tipo>::getIterador() {
    return new IteradorLista<tipo>(raiz->getSiguiente());
}
