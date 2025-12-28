/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Josue
 *
 * Created on 23 de mayo de 2024, 12:02 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>
#include "Pedido.h"
class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(const char* desc);
    void GetDescripcion(char *desc) const;
    void SetCodigo(const char* cod);
    void GetCodigo(char *cod) const;
    bool operator +=( class Pedido &pedido);
    void imprimeAtendidos(ofstream &)const;
    void imprimeNoAtendidos(ofstream &)const;
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[200];
    int clientes_no_servidos[200];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
    
};
bool operator >> (ifstream &arch, class Producto &producto);
ofstream & operator <<(ofstream &arch,const class Producto &prod); 
#endif /* PRODUCTO_H */

