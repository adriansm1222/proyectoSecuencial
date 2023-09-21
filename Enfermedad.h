//
// Created by adria on 19/5/2021.
//

#ifndef PROYECTO2_ENFERMEDAD_H
#define PROYECTO2_ENFERMEDAD_H
#include <iostream>
#include <sstream>

using namespace std;
class Enfermedad {
private:
    string nombre;
    string adn;
public:
    Enfermedad(string nombre="", string adn="");
    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getAdn() const;
    void setAdn(const string &adn);
    string toString();
};


#endif //PROYECTO2_ENFERMEDAD_H
