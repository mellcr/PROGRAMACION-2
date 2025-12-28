/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.h
 * Author: alulab14
 *
 * Created on 8 de septiembre de 2023, 08:02 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void lecturaDeProductos(const char *nomArch,char***&productos,int*&stock,double*&precios);
char*asignaCadenaExacta(const char*cad);
char **asignaMemoria(const char*cod,const char*desc);
void pruebaDeLecturaDeProductos(const char*nomArch,char***productos,int*stock,double*precios);
void imprimeCodYDesc(ofstream&arch, char **producto);
void lecturaDePedidos(const char*nomArch,int*&fechaPedidos,char***&codigoPedidos,int***&dniCantPedidos);
void asignaMemoriaExacta(char **&codigoPedidos,int**&dniCantPedidos,int arrNum);
int busca(int*buffFec, int fecha);
void asignaCodigos(char**buffCodPed ,char*cod, int arrNum);
void asignaDniCant(int**buffDniCant,int dni,int cant, int num);
void asignaDni(int *buffDniCant,int dni);
void asignaCant(int *buffDniCant,int cant);
void pruebaDeLecturaDeProductos(const char*nomArch,int*fechaPedidos,char***codigoPedidos,int***dniCantPedidos);
void imprimePedidos(ofstream &arch,char **codigoPedidos,int**dniCantPedidos);
void imprimeLinea(ofstream&arch,char c);
void reporteDeEnvioDePedidos(const char *nomArch,char***productos,int*stock,double*precios,
          int*fechaPedidos,char***codigoPedidos,int***dniCantPedidos);
void imprimePedidosFormato(ofstream&arch,char **codigoPedidos,int **dniCantPedidos,char***productos,double*precios,int*stock,double&totalIngresos,double&totalPerdidoFaltaStock);
int busca(char***productos,const char*codigoPedido);
#endif /* FUNCIONES_H */

