/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Func.h
 * Author: mell1
 *
 * Created on 26 de abril de 2024, 0:16
 */

#ifndef FUNC_H
#define FUNC_H
using namespace std;

 void cargaLibros(void * libros,const char *filename);
   char *leeCadDelim(ifstream  &arch, char delim);
    void *leeRegLib(ifstream &arch);
  void lecturaDeClientes(void *&clientes,const char *nombArch);
  void *leeCliente(ifstream &archCliente);
  char *leeCadena(ifstream &arch);
  void *leeLibros(ifstream &archLibros);
  void lecturaDeLibros(void *&libros,const char* nombrArch);
  
#endif /* FUNC_H */

