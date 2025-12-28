/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: mell1
 *
 * Created on 2 de mayo de 2024, 18:48
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H
using namespace std;

char *leeCadDelim(ifstream &arch, char delim);
void* leenum(ifstream &arch);
int cmpnum(const void *a, const void *b);
void  imprimenum(void *dato, ofstream &arch);
#endif /* LISTACONENTEROS_H */

