/* 
 * Proyecto: AsignacionDinamicaMemoriaExacta-2023-2
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 10 de abril de 2024, 17:06
 */

#include "Utils.h"
#include "AsignacionDinamicaMemoriaExacta.h"
using namespace std;

int main(int argc, char** argv) {
    char ***productos, ***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,
            dniCantPedidos);
    
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,
            precios,fechaPedidos,codigoPedidos,dniCantPedidos); 
    
    
    return 0;
}

/*cod(cadena), des(cadena), precio(int) stock(double)*/