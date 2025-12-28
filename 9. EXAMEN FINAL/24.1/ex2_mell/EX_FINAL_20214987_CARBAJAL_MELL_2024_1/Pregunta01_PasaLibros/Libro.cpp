/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 09:30 AM
 */
#include "Utils.h"
using namespace std; 
#include "Libro.h"

Libro::Libro() {
    nombre = nullptr; 
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(const char* nombre) {
    if(this->nombre !=nullptr)delete this->nombre; 
    
    this->nombre = new char [strlen(nombre)+1]; 
    strcpy(this->nombre,nombre); 
}

void Libro::GetNombre(char *c) const {
    if(nombre==nullptr) c[0] =0; 
    else strcpy(c,nombre);
}

void Libro::lee(ifstream &arch){
    char buff[200]{},c; 
    
    arch.getline(buff,200,','); 
    SetNombre(buff); 
    arch>>paginas>>c>>peso>>c; 
}
//////////
