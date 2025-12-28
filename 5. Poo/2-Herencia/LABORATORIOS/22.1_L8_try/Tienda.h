

/* 
 * File:   Tienda.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 10:46
 */

#ifndef TIENDA_H
#define TIENDA_H
#include "Pedido.h"
#include "CLiente.h"

class Tienda {
private:
    class Pedido lpedidos[800]; 
    class CLiente lclientes[800]; 
public:
    Tienda();
    Tienda(const Tienda& orig);
    virtual ~Tienda();
    void carga();
    void muestra(); 
    void actualiza(int ); 
    int buscarEnCliente(int dniBus);
};

#endif /* TIENDA_H */

