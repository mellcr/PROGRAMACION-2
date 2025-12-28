

/* 
 * File:   Nodo.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 22:24
 */

#ifndef NODO_H
#define NODO_H
#include "Boleta.h"
#include "Arbol.h"

class Nodo {
private:
    class Boleta dboleta;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

