

/* 
 * File:   Nodo.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:53
 */

#ifndef NODO_H
#define NODO_H
#include "Pedido.h"
#include "Lista.h"

class Nodo {
private:
    class Pedido *ped;
    class Nodo *sig;
    class Nodo *ant;
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    
    friend class Lista;
};

#endif /* NODO_H */

