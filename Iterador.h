//
// Created by adria on 1/6/2021.
//

#ifndef PROYECTO2_ITERADOR_H
#define PROYECTO2_ITERADOR_H

template<class tipo>
class Iterador {
public:
    virtual bool vacia()=0;
    virtual tipo *proximo()=0;
};


#endif //PROYECTO2_ITERADOR_H
