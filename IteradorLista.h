//
// Created by adria on 1/6/2021.
//

#ifndef PROYECTO2_ITERADORLISTA_H
#define PROYECTO2_ITERADORLISTA_H
#include "Iterador.h"
#include "Nodo.h"
#include "Paciente.h"
#include "Enfermedad.h"
template<class tipo>
class IteradorLista : public Iterador<tipo>{
private:
    Nodo<tipo> *cursor;
public:
    IteradorLista(Nodo<tipo> *nodo);
    virtual ~IteradorLista();
    bool vacia();
    tipo proximo();
    tipo primero();
    void volverInicio(Nodo<tipo> *primero);
};

template<>
class IteradorLista<Paciente> {
private:
    Nodo<Paciente> *cursor;
public:
    IteradorLista(Nodo<Paciente> *nodo){
        this->cursor=nodo;
    }

    virtual ~IteradorLista(){

    }

    bool vacia(){
        return (cursor!= nullptr);
    }

    Paciente *proximo(){
        Paciente *aux;
        if(vacia()){
            aux=cursor->getDato();
            cursor=cursor->getSiguiente();
            return aux;
        }
        return nullptr;
    }
};

template<>
class IteradorLista<Enfermedad> {
private:
    Nodo<Enfermedad> *cursor;

public:
    IteradorLista(Nodo<Enfermedad> *nodo) {
        this->cursor = nodo;
    }

    virtual ~IteradorLista(){

    }

    bool vacia() {
        return (cursor != nullptr);
    }

    Enfermedad *proximo() {
        Enfermedad *aux;
        if (vacia()) {
            aux = cursor->getDato();
            cursor = cursor->getSiguiente();
            return aux;
        }
        return nullptr;
    }
    void volverInicio(Nodo<Enfermedad> *primero){
        cursor=primero;
    }
};

/*
Se decidio implementar el patron de comportamiento Iterador, ya que permite recorrer de manera más sencilla los elementos de una estructura de datos,
en este caso una lista simplemente enlazada. Además, en distintas partes del código, dicho Iterador también ayuda a proteger las partes internas de la lista,
como se verá más adelante en la clase ContenedoraLista. El IteradorLista cuenta con una estructura sencilla: posee una característica privada interna de tipo Nodo llamada cursor,
esta característica se inicializa igualándola al primer nodo de la lista. Además, posee los métodos para realizar su función de recorrido. A continuación se explican cada uno de los métodos:
-bool vacia() devuelve true o false dependiendo si la estructura, en este caso la lista tiene más elementos o está vacía/se llegó al final de la misma.
-tipo proximo() con la ayuda de bool vacia() se realiza un ciclo para ir obteniendo los datos que contiene la lista.
-void volverInicio(Nodo *primero) este metodo solo se encuentra en la especialización respectiva de Enfermedad. Su función es la de regresar el cursor de la lista al primer elemento de la misma.
 */
/*
Como se puede observar, el patrón de comportamiento Iterador se modificó mediante la programación genérica para proporcionar un iterador genérico para cualquier lista instanciada a lo largo del código.
 */



#endif //PROYECTO2_ITERADORLISTA_H
