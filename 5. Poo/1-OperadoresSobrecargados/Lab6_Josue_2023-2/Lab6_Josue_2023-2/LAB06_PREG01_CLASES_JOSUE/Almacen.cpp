/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: Josue
 * 
 * Created on 23 de mayo de 2024, 12:14 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "Producto.h"
#include "Almacen.h"

Almacen::Almacen() {
    cantidad_clientes=0;
    cantidad_productos=0;
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

