/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Almacen.h
 * Author: Josue
 *
 * Created on 23 de mayo de 2024, 12:14 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Cliente.h"
#include "Producto.h"
class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    void cargar_clientes();
    void cargar_productos();
    void cargar_pedidos();
    int buscarCliente(int );
    int buscarProducto(const char * );
    void mostrar_datos();
    void imprimeLinea(char , ofstream &);
private:
    class Cliente arreglo_cliente[200];
    int cantidad_clientes;
    class Producto arreglo_productos[200];
    int cantidad_productos;
    
};

#endif /* ALMACEN_H */

