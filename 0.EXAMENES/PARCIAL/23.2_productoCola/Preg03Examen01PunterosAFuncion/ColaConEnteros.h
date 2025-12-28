/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConEnteros.h
 * Author: mell1
 *
 * Created on 6 de mayo de 2024, 1:48
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H
using namespace std;
void *leenumero(ifstream &arch);
void cargaEnteros(void *&cola,void *(*leenumero)(ifstream &),const char *filename);             
void mostrarEnteros(void *cola,void (*imprime)(void *dato, ofstream &arch),const char *filename);
void imprimenumero(void *dato, ofstream &arch);
#endif /* COLACONENTEROS_H */

