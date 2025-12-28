/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jean Carlos
 *
 * Created on 8 de abril de 2024, 21:45
 */

#include <cstdlib>

using namespace std;

#include "AsignacionDinamicaMemoriaExacta.h"

int main(int argc, char** argv) {
    
    char ***productos, **codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv", productos, stock, precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt", productos, stock, precios);
 

    return 0;
}

