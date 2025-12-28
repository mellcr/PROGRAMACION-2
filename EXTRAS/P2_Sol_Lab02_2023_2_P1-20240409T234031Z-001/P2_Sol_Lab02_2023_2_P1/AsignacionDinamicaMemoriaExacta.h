/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Jean Carlos
 *
 * Created on 8 de abril de 2024, 22:01
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;

void lecturaDeProductos(const char* nombArch , char *** &productos, int *&stock, double *&precios);
void pruebaDeLecturaDeProductos(const char* nombArch, char ***productos, int *stock,  double *precios);
void TerminarDeLeerProducto(char *buffcadena, char **bufferProd , ifstream &archProd);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

