/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 10:23 AM
 */
#include "Utils.h"
using namespace std;
#include "Libro.h"

Libro::Libro() {
    
}

Libro::Libro(const Libro& orig) {
    *this = orig;
}

Libro::~Libro() {
}

void Libro::SetTema(string tema) {
    this->tema = tema;
}

string Libro::GetTema() const {
    return tema;
}

void Libro::SetGenero(string genero) {
    this->genero = genero;
}

string Libro::GetGenero() const {
    return genero;
}

void Libro::SetAutor(string autor) {
    this->autor = autor;
}

string Libro::GetAutor() const {
    return autor;
}

void Libro::SetTitulo(string titulo) {
    this->titulo = titulo;
}

string Libro::GetTitulo() const {
    return titulo;
}

void Libro::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Libro::GetCodigo() const {
    return codigo;
}

///////////
void Libro::leeDatos(ifstream &arch){
    char buff[200];
    arch.getline(buff,200,','); 
    if(arch.eof()) return; 
    codigo = buff; 
    arch.getline(buff,200,','); 
    titulo  = buff; 
    arch.getline(buff,200,','); 
    autor  = buff; 
    arch.getline(buff,200,','); 
    genero  = buff; 
    arch.getline(buff,200); 
    tema  = buff; 
}