/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autor.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 10:24 AM
 */
#include "Utils.h"
using namespace std;
#include "Autor.h"

Autor::Autor(){
}

Autor::Autor(const Autor& orig) {
}

Autor::~Autor() {
}

void Autor::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Autor::GetNombre() const {
    return nombre;
}

void Autor::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Autor::GetCodigo() const {
    return codigo;
}

void Autor::leeDatos(ifstream &arch){
    char buff1[200], buff2[200]; 
    
    arch.getline(buff1,200,','); 
    if(arch.eof()) return; 
    codigo = buff1; 
     arch.getline(buff2,200,','); 
    nombre = buff2; 
}