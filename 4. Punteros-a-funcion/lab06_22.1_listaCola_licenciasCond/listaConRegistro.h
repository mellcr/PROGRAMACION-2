/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   listaConRegistro.h
 * Author: mell1
 *
 * Created on 2 de mayo de 2024, 21:28
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H
using namespace std;

char *leeCadDelim(ifstream &arch, char delim);
void* leeregistro(ifstream &arch);
    void  imprimeregistro(void *dato, ofstream &arch);
    int cmpregistro(const void *a, const void *b);

#endif /* LISTACONREGISTRO_H */

