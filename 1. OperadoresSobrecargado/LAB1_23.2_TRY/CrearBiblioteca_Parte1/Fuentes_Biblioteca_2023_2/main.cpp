/* 
 * Proyecto: Fuentes_Biblioteca_2023_2
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 4 de abril de 2024, 23:37
 */

#include "Utils.h"
using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#define NMAX 200
int main(int argc, char** argv) {
    struct Cliente clientes[NMAX];
    struct Producto productos[NMAX];
    
    ifstream archCli,archProd,archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.csv"); 
    AperturaDeUnArchivoDeTextosParaLeer(archProd,"Productos.csv");     
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"",clientes,productos)
    
    pruebaClientes();
    
    
    
    return 0;
}

