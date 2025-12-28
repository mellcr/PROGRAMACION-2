/* 
 * Proyecto: aprendiendoPunteroVoid
 * Archivo:   funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 21 de abril de 2024, 13:00
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
void leeRegistro(void *&persona);
void imprimeRegistro(void *persona);
void liberaEspacios(void *persona);
//CUANDO LAS ESTRUCTURAS SON MAS GRANDES
void *leeRegistro(void); // void->no tiene parametro

#endif /* FUNCIONES_H */

