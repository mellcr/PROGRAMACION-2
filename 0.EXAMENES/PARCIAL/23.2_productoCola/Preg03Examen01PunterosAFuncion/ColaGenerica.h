/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaGenerica.h
 * Author: mell1
 *
 * Created on 6 de mayo de 2024, 1:01
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

void generacola(void *&cola);
bool colaVacia(void *cola);

void encola(void *&cola, void *dato);
void *desencola(void *&cola);

#endif /* COLAGENERICA_H */

