//
// Created by adria on 19/5/2021.
//

#include "Paciente.h"

Paciente::Paciente(string nombre, string id, string adn, int enfermedades, float porcentajeA, float porcentajeC, float porcentajeG, float porcentajeT) {
    this->nombre=nombre;
    this->id=id;
    this->cadADN=adn;
    this->enfermedades=enfermedades;
    this->enfermedades=enfermedades;
    this->porcentajeA = porcentajeA;
    this->porcentajeC = porcentajeC;
    this->porcentajeG = porcentajeG;
    this->porcentajeT = porcentajeT;
    this->probabilidadUCI = 0.0;
    this->lEnfermedades = nullptr;
}

const string &Paciente::getNombre() const {
    return nombre;
}

void Paciente::setNombre(const string &nombre) {
    Paciente::nombre = nombre;
}

const string &Paciente::getId() const {
    return id;
}

void Paciente::setId(const string &id) {
    Paciente::id = id;
}

const string &Paciente::getAdn() const {
    return cadADN;
}

void Paciente::setAdn(const string &cadAdn) {
    Paciente::cadADN = cadAdn;
}

string Paciente::toString() {
    stringstream s;
    s<<"Nombre: "<<getNombre()<<endl;
    s<<"ID: "<<getId()<<endl;
    s<<"Cadena ADN: "<<getAdn()<<endl;
    return s.str();
}

int Paciente::getEnfermedades() const {
    return enfermedades;
}

void Paciente::setEnfermedades(int enfermedades) {
    Paciente::enfermedades = enfermedades;
}

vector<Enfermedad> *Paciente::getLEnfermedades() const {
    return lEnfermedades;
}

void Paciente::setLEnfermedades(vector<Enfermedad> *lEnfermedades) {
    Paciente::lEnfermedades = lEnfermedades;
}

float Paciente::getPorcentajeA() const {
    return porcentajeA;
}

void Paciente::setPorcentajeA(float porcentajeA) {
    Paciente::porcentajeA = porcentajeA;
}

float Paciente::getPorcentajeC() const {
    return porcentajeC;
}

void Paciente::setPorcentajeC(float porcentajeC) {
    Paciente::porcentajeC = porcentajeC;
}

float Paciente::getPorcentajeG() const {
    return porcentajeG;
}

void Paciente::setPorcentajeG(float porcentajeG) {
    Paciente::porcentajeG = porcentajeG;
}

float Paciente::getPorcentajeT() const {
    return porcentajeT;
}

void Paciente::setPorcentajeT(float porcentajeT) {
    Paciente::porcentajeT = porcentajeT;
}

const string &Paciente::getCadAdn() const {
    return cadADN;
}

void Paciente::setCadAdn(const string &cadAdn) {
    cadADN = cadAdn;
}

float Paciente::getProbabilidadUci() const {
    return probabilidadUCI;
}

void Paciente::setProbabilidadUci(float probabilidadUci) {
    probabilidadUCI = probabilidadUci;
}
