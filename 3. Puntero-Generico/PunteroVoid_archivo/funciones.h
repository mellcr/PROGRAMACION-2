/* 
 * Proyecto: aprendiendoPunteroVoid
 * Archivo:   funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 21 de abril de 2024, 13:00
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
using namespace std;
void leeRegistro(void *&persona);
void imprimeRegistro(void *persona);
void liberaEspacios(void *persona);
//CUANDO LAS ESTRUCTURAS SON MAS GRANDES
void *leeRegistro(ifstream &arch); // void->no tiene parametro]

////////////////////////////ARCHIVO///////////////////////////////////////
void leeDatos(void *&personas,int &numPer);
void ordenar(void *personas,int ini,int fin);
void imprimeDatos(void *personas,int numPer);
void cambiar(void *&a,void *&b);
int comparar(void *perI,void *perJ);
int compararNomb(void *perI,void *perJ);


#endif /* FUNCIONES_H */

