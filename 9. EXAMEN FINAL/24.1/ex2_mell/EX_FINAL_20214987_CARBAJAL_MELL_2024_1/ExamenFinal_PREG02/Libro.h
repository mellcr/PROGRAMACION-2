/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 10:23 AM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include "Utils.h"
using namespace std;

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetTema(string tema);
    string GetTema() const;
    void SetGenero(string genero);
    string GetGenero() const;
    void SetAutor(string autor);
    string GetAutor() const;
    void SetTitulo(string titulo);
    string GetTitulo() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    
    void leeDatos(ifstream &arch); 
private:
    string codigo; 
    string titulo; 
    string autor; 
    string genero; 
    string tema; 
    
};

#endif /* LIBRO_H */

