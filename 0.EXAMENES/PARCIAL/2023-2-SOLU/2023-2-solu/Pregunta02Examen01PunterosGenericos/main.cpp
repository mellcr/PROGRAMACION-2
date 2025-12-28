/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 5 de mayo de 2024, 10:40 PM
 */


#include "Pregunta02Examen01PunterosGenericos.h"

int main(int argc, char** argv) {
    void *productos;
    cargaProductos(productos,"Productos.csv");
    pruebaDeCargaDeProductos(productos);
    return 0;
}

