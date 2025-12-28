/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 5 de mayo de 2024, 10:56
 */

#include "utils.h"
#include "MemIncrementos.h"
using namespace std;

int main(int argc, char** argv) {
    char ***productos, ***codigoPedidos;
    int *stock, ***dniCantPedidos, *fechaPedidos;
    double *precios;
    
    lecturaDeProdutos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    lecturaDePedidos("Pedidos.csv",fechaPedidos, codigoPedidos,dniCantPedidos);
    ReporteDeEnviosDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,precios,
                                                     fechaPedidos,codigoPedidos,dniCantPedidos);
    return 0;
}

