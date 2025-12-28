/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 5 de mayo de 2024, 19:21
 */


#include "utils.h"
#include "Preg01Ex1PunterosMultiples.h"
using namespace std;


int main(int argc, char** argv) {
    int **fechaClienteCant;
    char **codigoDelProducto;
    
    cargarPedidos(fechaClienteCant,codigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCant,codigoDelProducto,"PruebaPed.txt");
    
    return 0;
}

