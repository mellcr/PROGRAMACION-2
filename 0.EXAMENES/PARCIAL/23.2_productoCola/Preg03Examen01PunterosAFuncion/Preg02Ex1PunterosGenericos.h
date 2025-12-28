/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Preg02Ex1PunterosGenericos.h
 * Author: mell1
 *
 * Created on 5 de mayo de 2024, 23:22
 */

#ifndef PREG02EX1PUNTEROSGENERICOS_H
#define PREG02EX1PUNTEROSGENERICOS_H
using namespace std;
char *leeCadDelim(ifstream &arch, char delim);
void cargarProductos(void *&productos,const char *filename);
void pruebaCargarProductos(void *productos);

void incrementarMemIncrem(void *&productos,int &numDat,int &capacity);
void asignarMemIncre(void *&productos,int &numDat,char *codProd,char *desc,double prec,int stockLeid);
void* asignaProducto(char *codProd,char *desc,double *precio,int *stock);

void pruebaCargarProductos(void *productos);
void imprimeProducto(void *productoDetalle, ofstream &arch);
#endif /* PREG02EX1PUNTEROSGENERICOS_H */

