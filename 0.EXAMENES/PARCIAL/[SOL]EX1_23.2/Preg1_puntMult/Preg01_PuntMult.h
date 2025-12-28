/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Preg01_PuntMult.h
 * Author: mell1
 *
 * Created on 13 de mayo de 2024, 11:36
 */

#ifndef PREG01_PUNTMULT_H
#define PREG01_PUNTMULT_H
using namespace std;
char *leeCadDelim(ifstream &arch, char delim);
void cargarPedidos(int **&fechaClienteCantidad,char **&codigoDelProducto,const char *filename);
void incrementaMemPed(int **&fechaClienteCantidad,char **&codigoDelProducto,int &numDat,int &cap);
void colocaDatosFechaCod(char *codProd,int dni,int  fecha,int cant,
        int *&fechaClienteCantidad,char *&codigoDelProducto);

void pruebaDeCargaDePedidos(int **fechaClienteCantidad,char **codigoDelProducto,
        const char *nombArch);
void imprimeLinea(ofstream &arch,char car);
//
int compara(const void *a,const void *b); 
#endif /* PREG01_PUNTMULT_H */

