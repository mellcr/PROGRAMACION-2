/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 13 de mayo de 2024, 11:20
 */

#include "utils.h"
#include "Preg01_PuntMult.h"
#include "Preg02_PuntGenerico.h"
using namespace std;


int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    void *productos;
    
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad,codigoDelProducto,"PruebaPed.txt");
    
    cargarProductos(productos,"Productos.csv");
    pruebaDeCargaDeProductos(productos);
    
    return 0;
}

