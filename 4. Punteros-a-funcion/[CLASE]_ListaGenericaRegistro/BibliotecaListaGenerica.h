/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: mell1
 *
 * Created on 30 de abril de 2024, 15:21
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H
using namespace std; 
// void insertarLista(void *dato,void *&lista_registros,int (*cmp)(const void *, const void *)); 
 void insertarLista(void *dato,void *&lista_registros,int (*cmp)(const void *, const void *)); 
 void  crear_lista(const char* filename,void *&lista_registros, void *(*leer_registro)(ifstream &),
         int (*cmp_registro_str)(const void * , const void *));
 void imprime_lista(const char *filename,void *lista_registros, 
         void (*imprimeRegistro)(ofstream &,void *)); 
 void imprimeRegistro(ofstream &arch,void *dato); 
 //mine
 void insertarListaAlFinal(void *dato, void *&lista_registros, int (*cmp)(const void *, const void *)) ; 
 void insertarListaAlInicio(void *dato, void *&lista_registros, int (*cmp)(const void *, const void *)); 
 
  void elimina_registro(void *dato); 
   void eliminar_lista(void *lista_registros, void (*elimina_registro)(void *)); 
   
#endif /* BIBLIOTECALISTAGENERICA_H */

