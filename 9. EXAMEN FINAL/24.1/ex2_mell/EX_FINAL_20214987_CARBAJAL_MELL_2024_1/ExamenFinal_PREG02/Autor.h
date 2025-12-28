/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autor.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 10:24 AM
 */

#ifndef AUTOR_H
#define AUTOR_H
#include "Libro.h"
#include "Utils.h"

using namespace std;

class Autor {
public:
    Autor();
    Autor(const Autor& orig);
    virtual ~Autor();
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    //
    void leeDatos(ifstream &arch); 
    
private:
    string codigo; 
    string nombre; 
    vector <class Libro> libros;  //profe me comento q lo trabaje con vector u.u
};

#endif /* AUTOR_H */

