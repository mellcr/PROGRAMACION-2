/* 
 * Proyecto: lab4_23.2
 * Archivo:   PunterosGenericos.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 23 de abril de 2024, 14:05
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
using namespace std; 
//funciones adicionales
void cargaProductos(void *&productos); 
char *leeCadDelim(ifstream &arch,char delim);
void *leeRegProd(ifstream &arch);

#endif /* PUNTEROSGENERICOS_H */

