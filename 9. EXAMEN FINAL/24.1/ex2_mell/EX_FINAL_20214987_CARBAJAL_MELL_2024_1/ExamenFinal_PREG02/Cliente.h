/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 10:27 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "Utils.h"
#include "Libro.h"
using namespace std; 

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetCantidad_libros_comprados(int cantidad_libros_comprados);
    int GetCantidad_libros_comprados() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
private:
    string codigo; 
    string nombre; 
    vector <class Libro> libros_comprados; 
    int cantidad_libros_comprados; 
    map <class Libro,vector<class Libro>> recomendaciones; 
    
};

#endif /* CLIENTE_H */

