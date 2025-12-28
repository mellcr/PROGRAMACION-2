

/* 
 * File:   Nodo.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de junio de 2024, 20:33
 */

#ifndef NODO_H
#define NODO_H
#include "Persona.h"
#include "Arbol.h"
// dato, izq , der
class Nodo {
private:
    class Persona dato;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
//    Nodo(const Nodo& orig);
//    virtual ~Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

