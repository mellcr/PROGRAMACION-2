

/* 
 * File:   Arbol.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de junio de 2024, 20:34
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Persona.h"
using namespace std;

class Arbol {
private:
    class Nodo *arbol;
    //extras
    void elimina(class Nodo *rec);
    void insertaRec(class Nodo *&arbol,const class Persona &dato);
    void mostrarOrdenRec(class Nodo *arbol, ofstream &arch);
    class Persona buscarRec(class Nodo *arbol,int dni);
public:
    Arbol();
    virtual ~Arbol();
    //extras
    void crear(const char *);
    void insertar(const class Persona &);
    void mostrarEnOrden(const char *);
    class Persona buscar(int);
};

#endif /* ARBOL_H */

