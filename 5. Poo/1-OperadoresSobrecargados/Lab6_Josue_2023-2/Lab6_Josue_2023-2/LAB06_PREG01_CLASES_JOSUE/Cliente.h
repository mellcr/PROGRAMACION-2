/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Josue
 *
 * Created on 22 de mayo de 2024, 11:12 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
#include "ProductoEntregado.h"
#include "Pedido.h"
class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* nomb);
    void  GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator += (const class Pedido &pedido); 
    void imprimirProductos(ofstream &)const;
private:
    int dni;
    char *nombre;
    int telefono;
    class ProductoEntregado productos_entregados[100];
    int cantidad_productos_entregados;
    double monto_total;
};


bool  operator >>(ifstream &arch, class Cliente &cliente);
ofstream& operator << (ofstream &arch, const class Cliente &cli);
#endif /* CLIENTE_H */

