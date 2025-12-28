

/* 
 * File:   Nodo.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de junio de 2024, 13:01
 */

#ifndef NODO_H
#define NODO_H
#include "Persona.h"
#include "Lista.h"

class Nodo {
private:
    class Persona dato;
    class Nodo *sig;
public:
    Nodo();
//    Nodo(const Nodo& orig);
//    virtual ~Nodo();
    friend class Lista;
};

#endif /* NODO_H */

