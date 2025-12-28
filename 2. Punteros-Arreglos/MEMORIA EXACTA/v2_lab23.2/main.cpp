/* 
 * Proyecto: v2_lab23.2
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 12 de abril de 2024, 0:23
 */

/*MELL ALESSANDRA CARBAJAL ROMAN 20214987*/
#include "Utils.h"
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    char ***productos,***codigoPedidos;
    int *stock, *fechaPedidos,**dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    
    return 0;
}

