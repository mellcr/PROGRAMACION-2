

/* 
 * File:   Categoria1.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:44
 */

#ifndef CATEGORIA1_H
#define CATEGORIA1_H

#include "Producto.h"


class Categoria1:public Producto {
private:
    int prioridad; // orden del prod en la prog de pedidos
    int minimo;
public:
    Categoria1();
    Categoria1(const Categoria1& orig);
    virtual ~Categoria1();
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void SetMinimo(int minimo);
    int GetMinimo() const;
    
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int obtienePrio(); 
};

#endif /* CATEGORIA1_H */

