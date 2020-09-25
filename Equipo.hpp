#include <string>

#ifndef EQUIPO_H
#define EQUIPO_H

using namespace std;

class Equipo
{
private:
    string nombre;
    int partidosGanados, partidosEmpatados, partidosPerdidos, golesAFavor, golesContra, difGoles, puntos, partidosTotal;

public:
    Equipo(){};
    Equipo(string _nombre, int _partidosGanados, int _partidosEmpatados, int _partidosPerdidos, int _golesAFavor, int _golesEnContra)
    {
        this->nombre = _nombre;
        this->partidosGanados = _partidosGanados;
        this->partidosEmpatados = _partidosEmpatados;
        this->partidosPerdidos = _partidosPerdidos;
        this->partidosTotal = _partidosGanados + _partidosEmpatados + _partidosPerdidos;
        this->golesAFavor = _golesAFavor;
        this->golesContra = _golesEnContra;
        this->difGoles = _golesAFavor - _golesEnContra;
        this->puntos = (_partidosGanados * 3) + (_partidosEmpatados);
    };
    string getNombre(){
        return nombre;
    }
    void setPuntos(int _puntos){
        puntos = _puntos;
    }
    int getPartidosTotal(){
        return this->partidosTotal;
    }
    int getPartidosGanados()
    {
        return this->partidosGanados;
    }
    int getPartidosPerdidos()
    {
        return this->partidosPerdidos;
    }
    int getPartidosEmpatados()
    {
        return this->partidosEmpatados;
    }
    int getGolesAFavor()
    {
        return this->golesAFavor;
    }
    int getGolesContra()
    {
        return this->golesContra;
    }
    int getDifGoles()
    {
        return this->difGoles;
    }
    int getPuntos()
    {
        return this->puntos;
    }
};

#endif
