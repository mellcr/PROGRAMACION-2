/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 22 de mayo de 2024, 10:28 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Pedido.h"
#include "Producto.h"
#include "Cliente.h"

int main(int argc, char** argv) {
    ifstream archProd ("Productos.csv",ios::in);
    if (not archProd.is_open()){
        cout << "ERROR: No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    ifstream archPed ("Pedidos.csv",ios::in);
    if (not archPed.is_open()){
        cout << "ERROR: No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    ifstream archCli ("Clientes.csv",ios::in);
    if (not archCli.is_open()){
        cout << "ERROR: No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    ofstream arch ("prueba.txt",ios::out);
    if (not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    
    class Pedido ped1;
    class Producto prod1, prod2;
    class Cliente cli1, cli2;
    
    archPed >> ped1;
    archCli >> cli1;
    archCli>> cli2;
    archProd >> prod1;
    
    cout << (archProd>> prod2)<<endl;
    
    prod1 += ped1;
    cli1 += ped1;
    
    
    arch << setprecision(2)<<fixed;
    arch << prod1<<endl;
    arch << cli1 << cli2;
    
    cout << ped1.GetDni_cliente()<<endl;
    cout<<prod1.GetStock()<<endl;
    
    
    
    return 0;
}

