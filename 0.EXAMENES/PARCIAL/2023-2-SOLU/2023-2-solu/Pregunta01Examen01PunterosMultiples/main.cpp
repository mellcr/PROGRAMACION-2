/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 5 de mayo de 2024, 01:20 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    pruebaCargaDePedidos(fechaClienteCantidad,codigoDelProducto,"PruebaPedidos.txt");
    return 0;
}

