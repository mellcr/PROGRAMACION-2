/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

#include "Utils.h"
#include "MemIncremento.h"
using namespace std;

int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,pedidosAtendidos);
    pruebaPedidosCli("PruebaPed.txt",pedidosClientes,pedidosLibros,pedidosAtendidos);
    
    return 0;
}

