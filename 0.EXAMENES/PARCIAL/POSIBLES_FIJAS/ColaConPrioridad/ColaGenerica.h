/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaGenerica.h
 * Author: mell1
 *
 * Created on 11 de mayo de 2024, 13:14
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

bool colavacia(void *cola);

void inicializaCola(void *&cola); 
void encola(void *&cola, void *dato); 
void encolaPrioridad(void *&cola, void *dato);
void *desencola(void *&cola); 
#endif /* COLAGENERICA_H */

