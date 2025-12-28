/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NPedido.h
 * Author: Josue
 *
 * Created on 13 de junio de 2024, 09:55 AM
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include "NPedido.h"
#include "Vehiculo.h"
class NPedido {
public:
    NPedido();
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* cod);
    void GetCodigo(char* cod) const;
    void asignaDatos(char *codPedido,int cant,double pesoProd);
    friend class Vehiculo;
private:
    char *codigo;
    int cantidad;
    double peso;
    class NPedido *sig;
};

#endif /* NPEDIDO_H */

