//
// Created by adria on 31/5/2021.
//

#ifndef PROYECTO2_CONTENEDORALISTAS_H
#define PROYECTO2_CONTENEDORALISTAS_H
#include "Lista.cpp"

/*
 El patrón estructural Fecade o Fachada se encuentra de manera ejemplificada en la clase Contenedora de Listas.
 Esto se justifica con que esta clase se compone de otras clases que requieren de la Contenedora de Listas para
 su correcto funcionamiento. Este ejemplo proporciona un acceso bastante práctico a una parte específica dentro de
 la funcionalida del programa. Este patrón tiene como ventaja el aislar el código de la complejidad de un subsistema.
 Se puede observar también, que la relación que existe entre ambos patrones es que el Iterador extrae el comportamiento
 de recorrido en este caso de las listas. Lo cual beneficia a la ContenedoraListas(Fachada o Fecade) que únicamente
 interactúa con el Iterador, o sea no tiene la necesidad de lidiar con el comportamiento de recorrido de las listas
 */
static bool a3=false;
class ContenedoraListas {
private:
    Lista<Enfermedad> *lEnfermedades;
    Lista<Paciente> *lPacientes;
public:
    ContenedoraListas(Lista<Enfermedad> *lEnfermedades=new Lista<Enfermedad>, Lista<Paciente> *lPacientes=new Lista<Paciente>);
    virtual ~ContenedoraListas();
    string analisis1();
    string analisis2();
    string analisis3();
    string busquedaEnfermedad(Paciente *p, Enfermedad *e);
    void setNumeroEnfermedades();
    Lista<Enfermedad> *getLEnfermedades() const;
    Lista<Paciente> *getLPacientes() const;
    void cargaDatos();
    void generarReporte();
    bool nombreEnfermedad(Paciente *p, Enfermedad *e);
};


#endif //PROYECTO2_CONTENEDORALISTAS_H
