/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Josue
 *
 * Created on 28 de mayo de 2024, 11:22 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"
#include "Espacio.h"
#include "Estante.h"
class Estante {
public:
    Estante();
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* cod);
    void GetCodigo(char* cod) const;
    void creaEspacios();
    bool operator +=( class Libro &libro);
    int calcularEspaciosLibres();
    void colocarLibro(int altLibro,int ancLibro, int sobrante); 
    void imprimeLibros(ofstream& arch)const ;
    void imprimeEspacios(ofstream& arch) const;
private:
    char *codigo;
    int anchura;
    int altura;
    class Libro libros[200];
    class Espacio *espacios;
    int cantidad_libros;
};

ifstream & operator >>(ifstream &arch,class Estante &estante);
void operator <<(ofstream &arch,const class Estante &est);
#endif /* ESTANTE_H */

