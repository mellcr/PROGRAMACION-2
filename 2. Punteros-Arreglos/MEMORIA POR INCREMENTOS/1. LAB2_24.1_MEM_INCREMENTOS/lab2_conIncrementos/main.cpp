/* 
 * Proyecto: lab2_conIncrementos
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 18 de abril de 2024, 9:12
 */

#include "Utils.h"
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros; 
    int **stock, **pedidosClientes; 
    bool **pedidosAtendidos; 
    
    lecturaDeLibros("Libros.csv",libros,stock); 
    //cout <<libros[0][0]<<endl;
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock); 
    
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,
            pedidosAtendidos); 
    
    
    return 0;
}

