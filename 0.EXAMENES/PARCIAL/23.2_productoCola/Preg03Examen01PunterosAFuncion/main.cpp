/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 6 de mayo de 2024, 0:57
 */


#include "funcUtils.h"

#include "Preg01Ex1PunterosMultiples.h"
#include "Preg02Ex1PunterosGenericos.h"

#include "ColaConEnteros.h"
#include "ColaGenerica.h"
#include "ColaConProductos.h"
using namespace std;

int main(int argc, char** argv) {
    char **codigoDelProducto; 
    int **fechaClienteCantidad;
    void *productos; 
    void *cola;
    
//    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv"); 
//    pruebaDeCargaDePedidos(fechaClienteCantidad,codigoDelProducto,"PruebaPed.txt");
//    cargarProductos(productos,"Productos.csv");
    //pruebaCargarProductos(productos); 
    
    
    cargaEnteros(cola,leenumero,"numeros.txt");
    mostrarEnteros(cola,imprimenumero,"reporte3Numeros.txt");
    
    
    
    return 0;
}

