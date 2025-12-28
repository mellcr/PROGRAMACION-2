/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Preg01Ex1PunterosMultiples.h
 * Author: mell1
 *
 * Created on 5 de mayo de 2024, 19:28
 */

#ifndef PREG01EX1PUNTEROSMULTIPLES_H
#define PREG01EX1PUNTEROSMULTIPLES_H
using namespace std;
void cargarPedidos(int **&fechaClienteCant,char **&codigoDelProducto,const char *filename );
char *leeCadDelim(ifstream &arch, char delim);
void incrementarMemIncrem(int **&fechaClienteCant,char **&codigoDelProducto, int & capacity, int &numDat);
void asignarEnMemIncrem(int *&fechaClienteCant,char *&codigoDelProducto, int &numDat, 
                char *codProd,int dni,int cant,int fecha);
void pruebaDeCargaDePedidos(int **fechaClienteCant,char **codigoDelProducto,const char *filename );
//QUICK SORT
void sort_Pedidos(int **&fechaClienteCant,char **&codigoDelProducto);
void swap2(int *&fechaI,int *&fechaJ,char *&codigoI,char *&codigoJ);
void quick_sort(int **&fechaClienteCant,char **&codigoDelProducto,int izq,int der);
#endif /* PREG01EX1PUNTEROSMULTIPLES_H */

