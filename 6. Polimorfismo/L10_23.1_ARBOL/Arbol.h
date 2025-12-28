

/* 
 * File:   Arbol.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 22:26
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include "Escala.h"
using namespace std;

//ORDEN:   ASC - cod 
class Arbol {
private:
    class Nodo *raiz;
    class Escala lescala[10];
    
    void insertarRec(class Nodo *&arbol,const class Boleta &dato);
    void imprimirEnOrdenRec(ofstream &arch,class Nodo *arbol);
public:
    Arbol();
    virtual ~Arbol();
    void crear(const char *filename);
    void imprimirEnOrden(const char *filename);
};

#endif /* ARBOL_H */

