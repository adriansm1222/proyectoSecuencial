//
// Created by adria on 19/5/2021.
//

#include "Enfermedad.h"

Enfermedad::Enfermedad(string nombre, string adn) {
    this->nombre=nombre;
    this->adn=adn;
}

const string &Enfermedad::getNombre() const {
    return nombre;
}

void Enfermedad::setNombre(const string &nombre) {
    Enfermedad::nombre = nombre;
}

const string &Enfermedad::getAdn() const {
    return adn;
}

void Enfermedad::setAdn(const string &adn) {
    Enfermedad::adn = adn;
}

string Enfermedad::toString() {
    stringstream s;
    s<<"Nombre: "<<getNombre()<<endl;
    s<<"Cadena ADN: "<<getAdn()<<endl;
    return s.str();
}
