/* 
 * Proyecto: v2_lab23.2
 * Archivo:   funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 12 de abril de 2024, 0:28
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H


void lecturaDeProductos(const char*filename,char***&productos,int *&stock,
        double *&precios);
void pruebaDeLecturaDeProductos(const char*filename,char***productos,int *stock,
        double *precios);
char * asignaCadena(char *cad);
char ** llenaBuffCodDesc(char *cod,char *desc);
void actualizaProductos(double *bufferPrecios,char ***bufferProd,int *bufferStock,
        char ***&productos,int *&stock,double *&precios,int numDat);




#endif /* FUNCIONES_H */

