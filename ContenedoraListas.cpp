//
// Created by adria on 31/5/2021.
//

#include "ContenedoraListas.h"

ContenedoraListas::ContenedoraListas(Lista<Enfermedad> *lEnfermedades, Lista<Paciente> *lPacientes) {
    this->lEnfermedades=lEnfermedades;
    this->lPacientes=lPacientes;
}

ContenedoraListas::~ContenedoraListas() {
    delete lPacientes;
    delete lEnfermedades;
}

Lista<Enfermedad> *ContenedoraListas::getLEnfermedades() const {
    return lEnfermedades;
}

Lista<Paciente> *ContenedoraListas::getLPacientes() const {
    return lPacientes;
}



/*
 * ======================================================
 * SECCION CARGA DE ENFERMEDADES Y PACIENTES
 * ======================================================
 * */

void ContenedoraListas::cargaDatos() {
    getLPacientes()->cargarPacientes();
    getLEnfermedades()->cargarEnfermedades();
}



/*
 * ====================================================
 * SECCION ANALISIS 1
 * ====================================================
 * */
void ContenedoraListas::analisis1() {
    if (getLEnfermedades()->listaVacia()) throw 1;
    IteradorLista<Paciente> *itP = getLPacientes()->getIterador();
    IteradorLista<Enfermedad> *itE = getLEnfermedades()->getIterador();
    while (itP->vacia()) {
        itE->volverInicio(getLEnfermedades()->primerNodo());
        Paciente *tempP = itP->proximo();
        vector<Enfermedad> *vEnfermedades = new vector<Enfermedad>;
        while (itE->vacia()) {
            Enfermedad *tempE = itE->proximo();
            if(nombreEnfermedad(tempP,tempE)){
                vEnfermedades->push_back(*tempE);
            }
        }
        tempP->setLEnfermedades(vEnfermedades);
        tempP->setEnfermedades(vEnfermedades->size());
    }
}

void ContenedoraListas::imprimirAnalisis1(string tiempo){
    stringstream s;
    s << getLPacientes()->toStringAnalisis1();
    s<<tiempo;
    ofstream archivo("Analisis1.txt", std::ios::trunc);
    archivo << s.str();
    archivo.close();
}


bool ContenedoraListas::nombreEnfermedad(Paciente *p, Enfermedad *e) {
    string adnE=e->getAdn();
    string adnP=p->getAdn();
    int esta=adnP.find(adnE);
    if(esta!=-1){
        return true;
    }else{
        return false;
    }
}

/*
 * ====================================================
 * SECCION ANALISIS 2
 * ====================================================
 * */

void ContenedoraListas::analisis2() {
    if (getLPacientes()->listaVacia()) throw 1;
    getLPacientes()->basesPorcentaje();
}

void ContenedoraListas::imprimirAnalisis2(string tiempo){
    stringstream s;
    s << getLPacientes()->toStringAnalisis2();
    s<<tiempo;
    ofstream archivo("Analisis2.txt", std::ios::trunc);
    archivo << s.str();
    archivo.close();
}


/*
 * ====================================================
 * SECCION ANALISIS 3
 * ====================================================
 * */
void ContenedoraListas::analisis3() {
    if (getLPacientes()->listaVacia() && getLEnfermedades()->listaVacia()) throw 1;
    getLPacientes()->ordenar();
    IteradorLista<Paciente> *itP=getLPacientes()->getIterador();
    IteradorLista<Enfermedad> *itE=getLEnfermedades()->getIterador();
    while(itP->vacia()){
        itE->volverInicio(getLEnfermedades()->primerNodo());
        Paciente *tempP=itP->proximo();
        if(tempP->getEnfermedades()>=2) {
            if(tempP->getEnfermedades()==2){
                tempP->setProbabilidadUci(40.0);
            }
            if(tempP->getEnfermedades()>=3){
                tempP->setProbabilidadUci(70.0);
            }
        }
    }
}

void ContenedoraListas::imprimirAnalisis3(string tiempo) {
    stringstream s;
    s << getLPacientes()->toStringAnalisis3();
    s << tiempo;
    ofstream archivo("Analisis3.txt", std::ios::trunc);
    archivo << s.str();
    archivo.close();
}

/*
Como se puede observar en algunos de los métodos de la clase ContenedoraListas se puede encontrar la utilidad del IteradorLista, ya que permite que el recorrido de dicha estructura se realice de manera independiente
protegiendo así la estructura interna de la lista, ya que no se accesa directamente desde ContenedoraLista. Además, se logra ver en funcionamiento al IteradorLista y sus distintas funciones, las cuales se explicaron en dicha clase.
 */