/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 09:35 AM
 */
#include "Utils.h"
using namespace std; 
#include "Revista.h"

Revista::Revista() {
    
}

Revista::Revista(const Revista& orig) {
}

Revista::~Revista() {
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

///////
void Revista::lee(ifstream &arch){
    Libro::lee(arch); 
    char c;
    arch>>ISSN>>c>>anho>>c>>numero;
    arch.get(); 
}