/* 
 * Proyecto: LAB2_CON_INCREMENTOS
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 16 de abril de 2024, 13:16
 */

#include <iostream>
#include <iomanip> 
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros; 
    int **stock,**pedidosClientes; 
    bool **pedidosAtendidos; 
    
    //PREG 1
    lecturaDeLibros("Libros.csv",libros,stock); 
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock); 
    //LIBROS-> COD , TITULO, AUT 
    //STOCK -> POR CADA LIBRO -> stock, cant no atendida 
    
    //PREGUNTA 2
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,
            pedidosLibros,pedidosAtendidos); 
    pruebaDeLecturaDeLibros("ReporteDeLibros.txt",libros,stock);
//    
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",
            pedidosClientes,pedidosLibros,pedidosAtendidos);
    return 0;
}

