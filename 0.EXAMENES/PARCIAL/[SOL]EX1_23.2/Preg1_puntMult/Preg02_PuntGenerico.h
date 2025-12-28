/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Preg02_PuntGenerico.h
 * Author: mell1
 *
 * Created on 13 de mayo de 2024, 23:21
 */

#ifndef PREG02_PUNTGENERICO_H
#define PREG02_PUNTGENERICO_H
using namespace std;
void cargarProductos(void *&productos,const char*filename);
void pruebaDeCargaDeProductos(void *productos);
void* leeRegistroProd(ifstream &arch);
#endif /* PREG02_PUNTGENERICO_H */

