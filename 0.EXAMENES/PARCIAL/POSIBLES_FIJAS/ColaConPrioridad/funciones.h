/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: mell1
 *
 * Created on 11 de mayo de 2024, 13:26
 */



#ifndef FUNCIONES_H
#define FUNCIONES_H
using namespace std;
void *leeReg(ifstream &arch);
void colitaCreadaPorNosotros(void *&cola,const char *filename); 
char *leeCadenaDelim(ifstream &arch, char delim);
void imprimeColaPri(void *cola,const char *filename);


#endif /* FUNCIONES_H */

