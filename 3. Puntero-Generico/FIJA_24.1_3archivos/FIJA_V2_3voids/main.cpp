/* 
 * Proyecto: FIJA_V2_3voids
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 24 de abril de 2024, 17:14
 */

#include "AperturaDeArchivos.h"
#include "utils.h"
#include "func.h"
using namespace std;

int main(int argc, char** argv) {
    void *libros, *clientes, *pedidos; 
    
    cargaClientes(clientes);
    cargaLibros(libros); 
    //cargaPedidos(pedidos,clientes,libros); 
    
    
    return 0;
}

