/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   colaGenerica.h
 * Author: mell1
 *
 * Created on 12 de mayo de 2024, 7:57
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

void inicializaCola(void *&cola);
bool colavacia(void *cola);
int sacaEdad(void *dato);
void imprimeCola(void *cola,const char *filename);

void encolaPrioridad_v2(void *&cola,void *dato);
#endif /* COLAGENERICA_H */

