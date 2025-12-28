

/* 
 * File:   Categoria2.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:46
 */

#ifndef CATEGORIA2_H
#define CATEGORIA2_H

#include "Producto.h"


class Categoria2: public Producto {
private:
    int prioridad; // orden del prod dentro de la prog de pedidos
    double descuento;
    
public:
    Categoria2();
    Categoria2(const Categoria2& orig);
    virtual ~Categoria2();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int obtienePrio(); 
};

#endif /* CATEGORIA2_H */

