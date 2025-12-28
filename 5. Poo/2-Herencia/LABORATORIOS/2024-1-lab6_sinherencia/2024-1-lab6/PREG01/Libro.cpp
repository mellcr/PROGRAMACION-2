/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Josue
 * 
 * Created on 28 de mayo de 2024, 11:16 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    nombre=nullptr;
    codigo=nullptr;
    colocado=false;
}



Libro::~Libro() {
    if(nombre!=nullptr)delete nombre;
    if(codigo!=nullptr)delete codigo;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char* nomb) {
    if(nombre!=nullptr)delete nombre;
    nombre=new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Libro::GetNombre(char* nomb) const {
    if(nombre==nullptr)nomb[0]=0;
    else strcpy(nomb,nombre);
}

void Libro::SetCodigo(const char* cod) {
    if(codigo!=nullptr)delete codigo;
    codigo=new char [strlen(cod)+1];
    strcpy(codigo,cod);
}

void Libro::GetCodigo(char* cod) const {
    if(codigo==nullptr)cod[0]=0;
    else strcpy(cod,codigo);
}

ifstream & operator >>(ifstream &arch, class Libro &libro){
    char cod[10],nombre[60];
    int ancho,alto;
    arch.getline(cod,10,',');
    if(arch.eof())return arch;
    arch.getline(nombre,60,','); 
    arch>>ancho;
    arch.get();
    arch>>alto;
    arch.get();
    libro.SetAlto(alto);
    libro.SetAncho(ancho);
    libro.SetCodigo(cod);
    libro.SetNombre(nombre);
    return arch;
}

void operator <<(ofstream &arch,const class Libro &lib){
    char cod[20],nom[60];
    lib.GetCodigo(cod);
    lib.GetNombre(nom);
    if(lib.IsColocado()){
        arch<<left<<setw(10)<<cod<<setw(25)<<nom<<right<<setw(4)<<lib.GetAncho()
            <<setw(9)<<lib.GetAlto()<<endl;
    }
    else{
        arch<<left<<setw(10)<<cod<<setw(25)<<"NO SE PUDO COLOCAR"<<right<<setw(4)<<lib.GetAncho()
            <<setw(9)<<lib.GetAlto()<<endl;
    }
}