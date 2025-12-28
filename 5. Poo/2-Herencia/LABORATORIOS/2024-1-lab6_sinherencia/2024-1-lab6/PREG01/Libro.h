/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Josue
 *
 * Created on 28 de mayo de 2024, 11:16 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
class Libro {
public:
    Libro();
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nomb);
    void GetNombre(char* nomb) const;
    void SetCodigo(const char* cod );
    void GetCodigo(char* cod) const;
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
};

ifstream & operator >>(ifstream &arch, class Libro &libro);
void operator <<(ofstream &arch,const class Libro &lib);
#endif /* LIBRO_H */

