/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 28 de mayo de 2024, 11:12 PM
 */

#include "Biblioteca.h"
using namespace std;
 
/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca biblioteca;
    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    biblioteca.posicionar_libros();
    biblioteca.mostrar_datos();
    return 0;
}

