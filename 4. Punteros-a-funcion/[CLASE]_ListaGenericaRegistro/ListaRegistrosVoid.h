/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaRegistrosVoid.h
 * Author: mell1
 *
 * Created on 30 de abril de 2024, 15:20
 */

#ifndef LISTAREGISTROSVOID_H
#define LISTAREGISTROSVOID_H


 char *leeCadDelim(ifstream &arch, char delim); 
void *leer_registro(ifstream &arch); 
int cmp_registro_str(const void * , const void *); 


#endif /* LISTAREGISTROSVOID_H */

