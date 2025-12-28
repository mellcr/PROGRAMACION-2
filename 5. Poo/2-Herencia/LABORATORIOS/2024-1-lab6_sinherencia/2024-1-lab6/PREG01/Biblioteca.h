/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Josue
 *
 * Created on 28 de mayo de 2024, 11:27 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
#include "Estante.h"
#include "Libro.h"
class Biblioteca {
public:
    Biblioteca();

private:
    class Estante estantes[100];
    int cantidad_estantes;
    class Libro libros[100];
    int cantidad_libros;
};

#endif /* BIBLIOTECA_H */

