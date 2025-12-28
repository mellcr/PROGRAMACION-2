

/* 
 * File:   Pedido.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 9:57
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
private:
    char *codigo; 
    int dni_cliente; 
    double sub_total; 
    int fecha; 
    char *estado; 
    double total; 
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
};

#endif /* PEDIDO_H */

