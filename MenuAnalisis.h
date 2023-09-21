//
// Created by adria on 31/5/2021.
//

#ifndef PROYECTO2_MENUANALISIS_H
#define PROYECTO2_MENUANALISIS_H
#include "ContenedoraListas.h"
#include <unistd.h>
#include <chrono>

/*
 En esta parte del código se ejemplifica la utilidad del patrón Fachada. Véase la clase MenuAnalisis como una clase
 Cliente y la clase ContenedoraListas como la Fachada o Fecade. El Cliente utiliza la Fachada en lugar de invocar
 directamente los objetos de las demás clases contenidas ya en la ContenedoraListas.
 */

class MenuAnalisis {
private:
    ContenedoraListas *contListas;
public:
    MenuAnalisis(ContenedoraListas *contListas=new ContenedoraListas);
    virtual ~MenuAnalisis();
    void menuPrincipal();
    void subMenuAnalisis();
    void limpiaMenu();
    void menuFallo();
};


#endif //PROYECTO2_MENUANALISIS_H
