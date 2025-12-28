/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 25 de abril de 2024, 19:46
 */

#include "Utils.h"
#include "Func.h"
using namespace std;

int main(int argc, char** argv) {
    void *libros, *clientes;
    lecturaDeLibros(libros,"Libros.csv");
    lecturaDeClientes(clientes,"Clientes.txt");
    completarPedidos(clientes,libros,"Pedidos.txt");
    
    
    return 0;
}

