

/* 
 * File:   Almacen.h
 * Author: BlueCod (mell1)
 *
 * Created on 22 de mayo de 2024, 18:13
 */

#include "Cliente.h"
#include "Producto.h"

#ifndef ALMACEN_H
#define ALMACEN_H

class Almacen {
private:
    class Cliente arreglo_clientes[500];
    int cantidad_clientes;
    class Producto arreglo_productos[500];
    int cantidad_productos;
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
};

#endif /* ALMACEN_H */

