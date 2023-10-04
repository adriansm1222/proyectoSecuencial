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
    float porcentajeA, porcentajeC, porcentajeG, porcentajeT, probabilidadUCI;
    vector<Enfermedad> *lEnfermedades;
public:
    Paciente(string nombre="", string id="", string adn="", int enfermedades=0, float porcentajeA = 0.0, float porcentajeC = 0.0, float porcentajeG = 0.0, float porcentajeT = 0.0);
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

    float getPorcentajeA() const;

    void setPorcentajeA(float porcentajeA);

    float getPorcentajeC() const;

    void setPorcentajeC(float porcentajeC);

    float getPorcentajeG() const;

    void setPorcentajeG(float porcentajeG);

    float getPorcentajeT() const;

    void setPorcentajeT(float porcentajeT);

    const string &getCadAdn() const;

    void setCadAdn(const string &cadAdn);

    float getProbabilidadUci() const;

    void setProbabilidadUci(float probabilidadUci);


};


#endif //PROYECTO2_PACIENTE_H
