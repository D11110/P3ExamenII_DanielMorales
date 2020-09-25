#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Equipo.hpp"
#include "Nodo.hpp"

using namespace std;

Nodo *selectionSort(Nodo *orig)
{
    Nodo *temp = orig;

    while (temp)
    {
        Nodo *min = temp;
        Nodo *r = temp->next_node();

        while (r)
        {
            if (min->getEquipo()->getPuntos() < r->getEquipo()->getPuntos())
                min = r;

            r = r->next_node();
        }

        Equipo *equipoTemporal = temp->getEquipo();
        temp->setEquipo(min->getEquipo());
        min->setEquipo(equipoTemporal);
        temp = temp->next_node();
    }

    return temp;
}

int main(int argc, char *argv[])
{
    string nombreArchivo = argv[1];
    fstream archivoTxt(nombreArchivo.c_str(), ios::in | ios::out);
    vector<string> archivoSeparadoPLineas;
    vector<Equipo *> equipos;

    while (!archivoTxt.eof())
    {
        string line;
        getline(archivoTxt, line);

        stringstream streamDeCadenaOrig(line);

        string cadenaResultante;

        while (getline(streamDeCadenaOrig, cadenaResultante, '\n'))
        {
            archivoSeparadoPLineas.push_back(cadenaResultante);
        }
    }

    Nodo *tope = nullptr;

    for (size_t i = 0; i < archivoSeparadoPLineas.size(); i++)
    {
        vector<string> equipo;
        stringstream streamDeLinea(archivoSeparadoPLineas.at(i));
        string cadenaRes;

        while (getline(streamDeLinea, cadenaRes, ','))
        {
            equipo.push_back(cadenaRes);
        }

        Equipo *temp = new Equipo(equipo[0], stoi(equipo[1]), stoi(equipo[2]), stoi(equipo[3]), stoi(equipo[4]), stoi(equipo[5]));
        equipos.push_back(temp);
        Nodo *nuevoNodo = new Nodo(temp);
        nuevoNodo->nextNode(tope);
        tope = nuevoNodo;
    }

    selectionSort(tope);
    int contParaIndice = 1;
    cout << "                " << "PJ" << setw(4) << "G" << setw(5) << "E" << setw(5) << "P" << setw(6) << "GA" << setw(5) << "GC" << setw(5) << "DG" << setw(5) << "PTS" << endl;

    while (tope != NULL)
    {
        cout << contParaIndice << " " << left << setw(14) << tope->getEquipo()->getNombre() << setw(5) << tope->getEquipo()->getPartidosTotal() << setw(5) << tope->getEquipo()->getPartidosGanados() << setw(5) << tope->getEquipo()->getPartidosEmpatados() << setw(5) << tope->getEquipo()->getPartidosPerdidos() << setw(5) << tope->getEquipo()->getGolesAFavor() << setw(5) << tope->getEquipo()->getGolesContra() << setw(5) << tope->getEquipo()->getDifGoles() << setw(5) << tope->getEquipo()->getPuntos() << endl;
        tope = tope->next_node();
        contParaIndice++;
    }
}
