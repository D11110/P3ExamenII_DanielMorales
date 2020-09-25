#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "Equipo.hpp"

using namespace std;

class Nodo
{
private:
    Nodo *nodo;
    Equipo *equipo;

public:
    Nodo() {}
    Nodo(Equipo *_equipo)
    {
        equipo = _equipo;
    }
    Nodo *nextNode(Nodo *nuevoTope)
    {
        this->nodo = nuevoTope;
        return nodo;
    }

    Nodo *next_node(){
        return nodo;
    }

    void setEquipo(Equipo *_equipo){
        equipo = _equipo;
    }

    Equipo *getEquipo(){
        return equipo;
    }
};

#endif // !NODO_H
