

/* 
 * File:   Categoria3.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:48
 */

#ifndef CATEGORIA3_H
#define CATEGORIA3_H

#include "Producto.h"


class Categoria3:public Producto {
private:
    int prioridad; // orden del prod dentro de la prog de pedidos
    double descuento;
public:
    Categoria3();
    Categoria3(const Categoria3& orig);
    virtual ~Categoria3();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int obtienePrio(); 
};

#endif /* CATEGORIA3_H */

