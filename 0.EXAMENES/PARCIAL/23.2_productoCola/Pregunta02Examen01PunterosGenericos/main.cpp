/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 5 de mayo de 2024, 23:11
 */

#include "utils.h"
#include "Preg02Ex1PunterosGenericos.h"
using namespace std;


int main(int argc, char** argv) {
    void *productos;
    
    cargarProductos(productos,"Productos.csv");
    pruebaCargarProductos(productos);
    
    return 0;
}

