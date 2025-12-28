/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 22 de mayo de 2024, 10:28 PM
 */

#include "Almacen.h"
using namespace std;
int main(int argc, char** argv) {
    Almacen almacen;
    almacen.cargar_clientes();
    almacen.cargar_productos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    return 0;
}

