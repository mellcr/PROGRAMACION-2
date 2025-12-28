/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 10:33 AM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Utils.h"
#include "Autor.h"
#include "Libro.h"
#include "Cliente.h"

using namespace std; 

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    //
    void cargar_libros(const char *filename);
    void cargar_autores(const char *filename);
    void cargar_clientes(const char *filename);
    void mostrar_recomendaciones(const char *filename);
    
private:
    map <string , class Autor> autores;
    vector <Libro> libros; 
    vector <Cliente> clientes; 
    
}; 

#endif /* BIBLIOTECA_H */

