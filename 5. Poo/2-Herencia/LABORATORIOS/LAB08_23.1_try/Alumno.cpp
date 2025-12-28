
/* 
 * File:   Alumno.cpp
 * Author: mell1
 * 
 * Created on 25 de mayo de 2024, 20:41
 */
#include "Utils.h"
#include "Alumno.h"
using namespace std;

Alumno::Alumno() {
    nombre = nullptr; 
    codigo = 0; 
    escala = 0; 
    total = 0; 
}

Alumno::~Alumno() {
    if(nombre) delete nombre; 
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}


int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::SetNombre(const char* nombre) {
    if(this->nombre) delete this->nombre;
    //se separa mem
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Alumno::GetNombre(char *c) const {
    if(this->nombre==nullptr) c[0] = 0;
    else strcpy(c,this->nombre);
}

void Alumno::leerDatos(ifstream &arch){
    char c, nomb[70]; 
    int codAlum, escala;
    
    arch>>codAlum;
    if(arch.eof()) return;
    arch.get();
    arch.getline(nomb,70,','); 
    arch>>escala;
    arch.get();
    
    SetCodigo(codAlum);
    SetEscala(escala);
    SetNombre(nomb);
}

void Alumno::imprime(ofstream &arch){
    arch<<left<<setw(10)<<codigo<<setw(40)<<nombre<<right<<setw(3)<<escala; 
}