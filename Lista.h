//
// Created by adria on 19/5/2021.
//

#ifndef PROYECTO2_LISTA_H
#define PROYECTO2_LISTA_H
#include "Nodo.h"
#include "Paciente.h"
#include "Enfermedad.h"
#include "IteradorLista.h"
#include <sstream>
#include <fstream>
#include <iomanip>
#include "dist/json/json.h"
template<class tipo>
class Lista {
private:
    Nodo<tipo> *raiz;
public:
    Lista();
    virtual ~Lista();
    bool listaVacia();
    void ingresar(tipo *dato);
    string toString();
    IteradorLista<tipo> *getIterador();
};

template<>
class Lista<Paciente> {
private:
    Nodo<Paciente> *raiz;
public:
    Lista() {
        raiz = new Nodo<Paciente>;
    }
    /*
     * ======================================================
     * SECCION METODOS NECESARIOS ANALISIS 1
     * ======================================================
     * */

    string toStringAnalisis1(){
        stringstream s;
        IteradorLista<Paciente> *itP=this->getIterador();
        while(itP->vacia()){
            Paciente *tempP=itP->proximo();
            s<<"Paciente: "<<endl;
            s<<tempP->toString();
            s<<"Enfermedades detectadas: "<<endl;
            for(int i = 0; i<tempP->getLEnfermedades()->size();i++){
                Enfermedad tempE = tempP->getLEnfermedades()->at(i);
                s<<"Enfermedad "<<tempE.getNombre()<<" detectada"<<endl;
            }
            s<<"-------------------------------------------------------------------------"<<endl;
        }
        return s.str();
    }

    /*
     * ======================================================
     * SECCION METODOS NECESARIOS PARA EL ANALISIS 2
     * */
    string toStringAnalisis2(){
        stringstream s;
        IteradorLista<Paciente> *iter = this -> getIterador();
        if(listaVacia()){
            s<<"Lista vacia"<<endl;
        }else {
            while(iter->vacia()){
                Paciente *aux=iter->proximo();
                s << aux->toString();
                s << "Porcentaje Base A: " << setprecision(4) << to_string(aux->getPorcentajeA()) << "%"
                  << endl;
                s << "Porcentaje Base T: " << setprecision(4) << to_string(aux->getPorcentajeT()) << "%"
                  << endl;
                s << "Porcentaje Base G: " << setprecision(4) <<  to_string(aux->getPorcentajeG()) << "%"
                  << endl;
                s << "Porcentaje Base C: " << setprecision(4) << to_string(aux->getPorcentajeC()) << "%"
                  << endl;
                s<<"-------------------------------------------------------------------------"<<endl;
            }
        }
        return s.str();
    }

    float porcentajeBase(char base, string adn){
        float cont=0;
        for(int i=0; i<adn.length()-1; i++){
            if(base==adn[i]){
                cont++;
            }
        }
        return (cont/adn.length())*100;
    }

    void basesPorcentaje(){
        char bases[4]={'A', 'T', 'G', 'C'};
        IteradorLista<Paciente> *iter = this -> getIterador();
        if(listaVacia()){
            return;
        }else {
            while(iter->vacia()){
                Paciente *aux=iter->proximo();
                aux->setPorcentajeA(porcentajeBase(bases[0], aux->getAdn()));
                aux->setPorcentajeC(porcentajeBase(bases[3], aux->getAdn()));
                aux->setPorcentajeG(porcentajeBase(bases[2], aux->getAdn()));
                aux->setPorcentajeT(porcentajeBase(bases[1], aux->getAdn()));
            }
        }
    }
    /*
     * ======================================================
     * SECCION METODOS NECESARIOS PARA EL ANALISIS 3
     * */
    string toStringAnalisis3(){
        stringstream s;
        IteradorLista<Paciente> *iter = this -> getIterador();
        if(listaVacia()){
            s<<"Lista vacia"<<endl;
        }else {
            while(iter->vacia()){
                Paciente *aux=iter->proximo();
                if(aux->getEnfermedades()>=2) {
                    s << "Paciente: " << endl;
                    s << aux->toString();
                    s << "Enfermedades detectadas: " << endl;
                    for (const auto & i : *aux->getLEnfermedades()) {
                        s << i.getNombre() + " detectada."<<endl;
                    }
                    if(aux->getEnfermedades()==2){
                        s<<"40% de probabilidades de ocupar UCI"<<endl;
                        s<< "-------------------------------------------------------------------------" << endl;
                    }
                    if(aux->getEnfermedades()>=3){
                        s<<"70% de probabilidades de ocupar UCI"<<endl;
                        s<< "-------------------------------------------------------------------------" << endl;
                    }
                }
            }
        }
        return s.str();
    }

    int maximoEnfermedades() {
        int max = 0;
        IteradorLista<Paciente> *iter = getIterador();
        if (listaVacia()) {
            return max;
        } else {
            while (iter->vacia()) {
                Paciente *aux = iter->proximo();
                if(aux->getEnfermedades()>max){
                    max=aux->getEnfermedades();
                }
            }
        }
        return max;
    }

    void ordenar(){
        Nodo<Paciente> *aux1;
        Nodo<Paciente> *aux2;
        Paciente *auxPaciente;
        if(listaVacia()){
            return;
        }else {
            while(primerNodo()->enfermedadesDato()!=maximoEnfermedades()) {
                aux1 = primerNodo();
                while (aux1->getSiguiente() != nullptr) {
                    aux2 = aux1->getSiguiente();
                    while (aux2 != nullptr) {
                        if (aux1->enfermedadesDato() < aux2->enfermedadesDato()) {
                            auxPaciente = aux2->getDato();
                            aux2->setDato(aux1->getDato());
                            aux1->setDato(auxPaciente);
                        }
                        aux2 = aux2->getSiguiente();
                    }
                    aux1 = aux1->getSiguiente();
                }
            }
        }
    }

    /*
     * ======================================================
     * SECCION CARGA DE PACIENTES
     * ======================================================
     * */
    void cargarPacientes(){
        ifstream archivo("CadenaADN.csv" ,ios::out);
        char delim=';';
        string linea;
        string nombre, id, cadADN;
        if(archivo.is_open()) {
            while (getline(archivo, linea)) {
            stringstream s(linea);
            getline(s, nombre, delim);
            getline(s, id, delim);
            getline(s, cadADN, delim);
            Paciente *nPaciente = new Paciente(nombre, id, cadADN, 0);
            ingresar(nPaciente);
            }
            archivo.close();
        }else throw 2;
    }

    /*
     * ======================================================
     * SECCION METODOS BASICOS DE LA LISTA DE PACIENTES
     * ======================================================
     */
    void ingresar(Paciente *dato) {
        Nodo<Paciente> *nodoNuevo = new Nodo<Paciente>;
        nodoNuevo->setDato(dato);
        nodoNuevo->setSiguiente(raiz->getSiguiente());
        raiz->setSiguiente(nodoNuevo);
    }

    bool listaVacia(){
        if(raiz->getSiguiente()==nullptr){
            return true;
        }
        return false;
    }

    IteradorLista<Paciente> *getIterador() {
        return new IteradorLista<Paciente>(primerNodo());
    }

    Nodo<Paciente> *primerNodo(){
        return raiz->getSiguiente();
    }

    virtual ~Lista() {
        Nodo<Paciente> *temp;
        Nodo<Paciente> *anterior;
        if (raiz->getSiguiente() == nullptr) {
            delete raiz;
        } else {
            while (raiz->getSiguiente() != nullptr) {
                temp = raiz;
                while (temp->getSiguiente() != nullptr) {
                    anterior = temp;
                    temp = temp->getSiguiente();
                }
                anterior->setSiguiente(nullptr);
                delete temp;
            }
        }
    }

    string toString() {
        stringstream s;
        auto *temp = new Nodo<Paciente>;
        if (listaVacia()) {
            s << "Lista vacia" << endl;
        } else {
            temp = raiz->getSiguiente();
            while (temp != nullptr) {
                s << temp->toStringDato();
                temp = temp->getSiguiente();
            }
        }
        return s.str();
    }
};

template<>
class Lista<Enfermedad>{
private:
    Nodo<Enfermedad> *raiz;
public:
    Lista() {
        raiz = new Nodo<Enfermedad>;
    }

    virtual ~Lista() {
        Nodo<Enfermedad> *temp;
        Nodo<Enfermedad> *anterior;
        if (raiz->getSiguiente() == nullptr) {
            delete raiz;
        } else {
            while (raiz->getSiguiente() != nullptr) {
                temp = raiz;
                while (temp->getSiguiente() != nullptr) {
                    anterior = temp;
                    temp = temp->getSiguiente();
                }
                anterior->setSiguiente(nullptr);
                delete temp;
            }
        }
    }

    string toString() {
        stringstream s;
        Nodo<Enfermedad> *temp = new Nodo<Enfermedad>;
        if (listaVacia()) {
            s << "Lista vacia" << endl;
        } else {
            temp = raiz->getSiguiente();
            while (temp != nullptr) {
                s << temp->toStringDato();
                temp = temp->getSiguiente();
            }
        }
        return s.str();
    }

    void ingresar(Enfermedad *dato) {
        Nodo<Enfermedad> *nodoNuevo = new Nodo<Enfermedad>;
        nodoNuevo->setDato(dato);
        nodoNuevo->setSiguiente(primerNodo());
        raiz->setSiguiente(nodoNuevo);
    }

    bool listaVacia(){
        if(raiz->getSiguiente()==nullptr){
            return true;
        }
        return false;
    }

    void cargarEnfermedades(){
        ifstream entrada("ListaSecuenciaEnfermedad.JSON");
        Json::Value obj;
        Json::Reader reader;
        string nombre, adn;
        if(entrada.is_open()) {
            reader.parse(entrada, obj);
            for (int i = 0; i < obj.size(); i++) {
                nombre = obj[i]["nombre"].asString();
                adn = obj[i]["secuencia"].asString();
                ingresar(new Enfermedad(nombre, adn));
            }
            entrada.close();
        }else throw 3;
    }

    IteradorLista<Enfermedad> *getIterador() {
        return new IteradorLista<Enfermedad>(primerNodo());
    }

    Nodo<Enfermedad> *primerNodo(){
        return raiz->getSiguiente();
    }

};
/*
En esta sección del código se ve implementada la programación genérica, ya que surge la necesidad de agrupar datos y manejarlos. En este caso, con la implementación de una lista simple genérica se facilita el manejo de una colección de datos de cualquier instancia
 a lo largo del programa, lo que compacta y facilita la reutilización del código, ya que no hay necesidad de implementar una nueva clase por cada lista de elementos que se desea.

 */
#endif //PROYECTO2_LISTA_H
