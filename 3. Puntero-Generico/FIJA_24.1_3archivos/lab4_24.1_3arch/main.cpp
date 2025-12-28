/* 
 * Proyecto: lab4_24.1_3arch
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 24 de abril de 2024, 8:25
 */

#include "Utils.h"
#include "funcionesPG.h"
using namespace std;

int main(int argc, char** argv) {
    void *clientes, *libros;
    
    cargaClientes(clientes); 
    cargaLibros(libros); 
    cargaPedidos(clientes,libros); 
    imprimereporte(clientes);
    return 0;
}

