/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 09:33 AM
 */
#include "Utils.h"
using namespace std; 
#include "Novela.h"

Novela::Novela() {
    autor = nullptr; 
    editorial = nullptr; 
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
}

void Novela::SetEditorial(const char* editorial) {
    if(this->editorial !=nullptr)delete this->editorial; 
    
    this->editorial = new char [strlen(editorial)+1]; 
    strcpy(this->editorial,editorial); 
}

void Novela::GetEditorial(char*c) const {
    if(editorial==nullptr) c[0] =0; 
    else strcpy(c,editorial);
}

void Novela::SetAutor(const char* autor) {
    if(this->autor !=nullptr)delete this->autor; 
    
    this->autor = new char [strlen(autor)+1]; 
    strcpy(this->autor,autor); 
}

void Novela::GetAutor(char*c) const {
    if(autor==nullptr) c[0] =0; 
    else strcpy(c,autor);
}


///////
void Novela::lee(ifstream &arch){
    Libro::lee(arch); 
    char buff[200]{},buff2[200],c; 
    
    arch.getline(buff,200,','); 
    SetAutor(buff); 
    arch.getline(buff2,200,'\n'); 
    SetEditorial(buff2); 
}

