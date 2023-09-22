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
    }
}

void ContenedoraListas::imprimirAnalisis1(string tiempo){
    stringstream s;
    s << getLPacientes()->toStringAnalisis1();
    s<<tiempo;
    ofstream archivo("analisis1.txt", std::ios::trunc);
    archivo << s.str();
    archivo.close();
}

string ContenedoraListas::analisis2() {
    if (getLPacientes()->listaVacia()) throw 1;
    return getLPacientes()->basesPorcentaje();
}

string ContenedoraListas::analisis3() {
    if (getLPacientes()->listaVacia() && getLEnfermedades()->listaVacia()) throw 1;
    stringstream s;
    setNumeroEnfermedades();
    getLPacientes()->ordenar();
    IteradorLista<Paciente> *itP=getLPacientes()->getIterador();
    IteradorLista<Enfermedad> *itE=getLEnfermedades()->getIterador();
    while(itP->vacia()){
        itE->volverInicio(getLEnfermedades()->primerNodo());
        Paciente *tempP=itP->proximo();
        if(tempP->getEnfermedades()>=2) {
            s << "Paciente: " << endl;
            s << tempP->toString();
            s << "Enfermedades detectadas: " << endl;
            while (itE->vacia()) {
                Enfermedad *tempE = itE->proximo();
                s << busquedaEnfermedad(tempP, tempE);
            }
            if(tempP->getEnfermedades()==2){
                s<<"40% de probabilidades de ocupar UCI"<<endl;
                s << "-------------------------------------------------------------------------" << endl;
            }
            if(tempP->getEnfermedades()>=3){
                s<<"70% de probabilidades de ocupar UCI"<<endl;
                s << "-------------------------------------------------------------------------" << endl;
            }
        }
    }
    a3=true;
    return s.str();
}

string ContenedoraListas::busquedaEnfermedad(Paciente *p, Enfermedad *e) {
    stringstream s;
    if(nombreEnfermedad(p, e)){
        s<<"Enfermedad "<<e->getNombre()<<" detectada"<<endl;
    }
    return s.str();
}

Lista<Enfermedad> *ContenedoraListas::getLEnfermedades() const {
    return lEnfermedades;
}

Lista<Paciente> *ContenedoraListas::getLPacientes() const {
    return lPacientes;
}


void ContenedoraListas::setNumeroEnfermedades() {
    IteradorLista<Paciente> *itP=getLPacientes()->getIterador();
    IteradorLista<Enfermedad> *itE=getLEnfermedades()->getIterador();
    string adnE;
    string adnP;
    int esta;
    while(itP->vacia()) {
        itE->volverInicio(getLEnfermedades()->primerNodo());
        Paciente *tempP = itP->proximo();
        while (itE->vacia()) {
            Enfermedad *tempE = itE->proximo();
            adnE=tempE->getAdn();
            adnP=tempP->getAdn();
            esta=adnP.find(adnE);
            if (esta!=-1){
                tempP->setEnfermedades(tempP->getEnfermedades()+1);
            }
        }
    }
}

void ContenedoraListas::cargaDatos() {
    getLPacientes()->cargarPacientes();
    getLEnfermedades()->cargarEnfermedades();
}

void ContenedoraListas::generarReporte() {
    if(!a3) throw 5;
    ofstream salida("reporteCCSS.JSON");
    IteradorLista<Paciente> *itP=getLPacientes()->getIterador();
    IteradorLista<Enfermedad> *itE=getLEnfermedades()->getIterador();
    Json::StreamWriterBuilder builder;
    builder["commentStyle"]="None";
    builder["identation"]="   ";
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    Json::Value clase;
    Json::Value arreglo(Json::arrayValue);
    while(itP->vacia()){
        itE->volverInicio(getLEnfermedades()->primerNodo());
        Paciente *tempP=itP->proximo();
        int numEnf=tempP->getEnfermedades();
        int index=0;
        string enfermedadesEnc[10];
        stringstream s;
        if(tempP->getEnfermedades()>=2) {
            clase["nombre"]=tempP->getNombre();
            clase["id"]=tempP->getId();
            clase["cadena adn"]=tempP->getAdn();
            while (itE->vacia()) {
                Enfermedad *tempE = itE->proximo();
                if(nombreEnfermedad(tempP, tempE)){
                    enfermedadesEnc[index]=tempE->getNombre();
                    index+=1;
                }
            }
            for(int i=0; i<numEnf; i++){
                s<<enfermedadesEnc[i]<<", ";
            }
            clase["enfermedades"]=s.str();
            if(tempP->getEnfermedades()==2){
                clase["UCI"]="40%";
            }
            if(tempP->getEnfermedades()>=3){
                clase["UCI"]="70%";
            }
            arreglo.append(clase);
        }
    }
    writer->write(arreglo, &salida);
    salida.close();
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
Como se puede observar en algunos de los métodos de la clase ContenedoraListas se puede encontrar la utilidad del IteradorLista, ya que permite que el recorrido de dicha estructura se realice de manera independiente
protegiendo así la estructura interna de la lista, ya que no se accesa directamente desde ContenedoraLista. Además, se logra ver en funcionamiento al IteradorLista y sus distintas funciones, las cuales se explicaron en dicha clase.
 */