//
// Created by adria on 19/5/2021.
//

#ifndef PROYECTO2_PACIENTE_H
#define PROYECTO2_PACIENTE_H
#include <iostream>
#include <sstream>
#include <vector>
#include "Enfermedad.h"

using namespace std;
class Paciente {
private:
    string nombre;
    string id;
    string cadADN;
    int enfermedades;
    vector<Enfermedad> *lEnfermedades;
public:
    Paciente(string nombre="", string id="", string adn="", int enfermedades=0);
    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getId() const;
    void setId(const string &id);
    const string &getAdn() const;
    void setAdn(const string &cadAdn);
    int getEnfermedades() const;
    void setEnfermedades(int enfermedades);
    string toString();

    vector<Enfermedad> *getLEnfermedades() const;

    void setLEnfermedades(vector<Enfermedad> *lEnfermedades);


};


#endif //PROYECTO2_PACIENTE_H
