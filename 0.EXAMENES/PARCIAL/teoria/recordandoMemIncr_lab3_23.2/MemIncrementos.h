/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MemIncrementos.h
 * Author: mell1
 *
 * Created on 5 de mayo de 2024, 11:34
 */

#ifndef MEMINCREMENTOS_H
#define MEMINCREMENTOS_H
using namespace std;

char *leeCadDelim(ifstream &arch, char delim);
void lecturaDeProdutos(const char *filename,char ***&productos,int *&stock,double *&precios);
void pruebaDeLecturaDeProductos(const char *filename,char ***productos,int *stock,double *precios);
void incrementarMemInc(char ***&productos,int *&stock,double *&precios,int &capacity,int &numDat);
void insertarEnMemoriaProd(char *codProd,char *desc,double preciosLect,int stockLeido,
                char **&productos,int &stock,double &precios,int &numDat);
//
void lecturaDePedidos(const char *filename,int *&fechaPedidos, char ***&codigoPedidos,int ***&dniCantPedidos);
int buscarFecha(int fechaBus,int *fechaPedidos);
void asignaMemFecha(int *&fechaPedidos,int &numFecha,int &capFechas, char ***&codigoPedidos,
        int ***&dniCantPedidos);
void colocarCodPed(char *codLeido,int cantLeida,int dniLeid,
        char **&codigoPedidos,int **&dniCantPedidos, int &cantPed,int &capPed);
void asignaMemPedidos( char **&codigoPedidos,int **&dniCantPedidos,int &numPed, int &capPed);
//
void ReporteDeEnviosDePedidos(const char *namefile,char***producto,int*&stock,double *precios,
                                                 int *fechaPedidos,char ***codigoPedidos, int ***dniCantPedidos);
void ImprimirLinea(ofstream &arch,int cant ,char letra);
int BuscarProducto(char ***producto,char *codigoPedidos);
void VerificacionStockyCalculoIngreso(ofstream &arch,double precio, int cantidad,int &stock,
        double &montoIngresado,double &montoPerdido);
void ImprimirPedidos(ofstream &arch,int **dniCantPedidos,char **codigoPedidos,char ***producto,
        int *&stock, double *precio);
#endif /* MEMINCREMENTOS_H */

