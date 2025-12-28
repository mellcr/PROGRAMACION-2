/* 
 * Proyecto: lab4_23.2
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 23 de abril de 2024, 10:23
 */

#include "Utils.h" 
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
using namespace std;

int main(int argc, char** argv) {
    void *productos, *clientes; 
    
    cargaProductos(productos); 
    cargaClientes(clientes); 
    cargaPedidos(productos,clientes); 
//    imprimereporte(clientes); 
    
    
    return 0;
}

