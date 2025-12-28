/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: mell1
 *
 * Created on 2 de mayo de 2024, 18:09
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H
using namespace std;

void crearLista(void *&lista,void* (*lee)(ifstream &),int (*cmp)(const void *, const void *),const char *filename);
void insertarListaOrdenado(void *dato,void *&lista,int (*cmp)(const void *, const void *));
void inicializaLista(void *&lista);
void imprimeLista(void *lista,void (*imprime)(void *, ofstream &),const char*filename);
void uneLista(void *&lista1,void *&lista2);
#endif /* BIBLIOTECALISTAGENERICA_H */

