/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 25 de abril de 2024, 20:09
 */

#include "utils.h"
#include "MuestraPunteros.h"
#include "func.h"
using namespace std;

int main(int argc, char** argv) {
    void *productos, *clientes; 
    cargaProductos(productos,"Productos2.csv");
    cargaClientes(clientes,"Clientes2.csv");
    cargaPedidos(productos,clientes);
    imprimerepfinal(clientes);
    return 0;
}

