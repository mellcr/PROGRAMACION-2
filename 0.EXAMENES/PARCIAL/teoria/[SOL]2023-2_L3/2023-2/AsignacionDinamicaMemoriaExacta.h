/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Josue
 *
 * Created on 18 de abril de 2024, 04:43 AM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,double *&precios);
char *leerCadena(ifstream &arch,char limitador);
void aumentarEspacios(char ***&productos,int *&stock,double *&precios,
        int &cantDatos,int &cap);
void asignamosDatosProductos(char **&productos,int &stock,double &precios,char *codigo,
        char *nombre,int stockInicial,double precio);
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,int *stock,
        double *precios);
void imprimeLinea(ofstream &archRep,int lineas,char car);
void imprimirDatosProducto(ofstream &archRep,char **productos);
void lecturaDePedidos(const char*nombArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos);
int buscarFecha(int *fechaPedidos,int fecha,int cantFechas);
void agregarFecha(int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos,
        int &posFecha,int &cantFechas,int fecha,int *cantPedidos,int *capPedidos,int &capFechas);
void aumentarEspacios(int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos,
        int &capFechas,int &cantFechas);
void agregarPedidos(char **&codigoPedidos,int **&dniCantPedidos,int &cant,
        int &cap,int cantidad,int dni,char *cod);
void aumentarEspacioPedidos(char **&codigoPedidos,int **&dniCantPedidos,int &cant,
        int &cap);
void pruebaDeLecturaDePedidos(const char*nombArch,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos);
void imprimePedidos(char **codigoPedidos,int **dniCantPedidos,ofstream &archRep);
void reporteDeEnvioDePedidos(const char*nombArch,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos);
void imprimirProductos(char **codigoPedidos,int **dniCantPedidos,char ***productos,
        int *stock,double *precios,ofstream &archRep,double &totalIngresado,double &totalperdido);
int buscarProducto(char *codigoPedidos,char ***productos);
#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

