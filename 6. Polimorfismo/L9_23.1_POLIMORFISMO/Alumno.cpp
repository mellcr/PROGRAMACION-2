
/* 
 * File:   Alumno.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 14:32
 */
#include "Utils.h"
#include "Alumno.h"
using namespace std;

Alumno::Alumno() {
    nombre = nullptr;
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

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
            
}

void Alumno::GetNombre(char* c) const {
    if(this->nombre==nullptr) c[0] = 0;
    else strcpy(c,this->nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::lee(ifstream &arch){
    char buffN[50],c;
    
    arch>>codigo;
    if(arch.eof()) return;
    arch.get();
    arch.getline(buffN,50,',');
    arch>>escala>>c>>creditos>>c;
    
    SetNombre(buffN);
}

void Alumno::actualizatotal(double prec){
    total = creditos*prec;
}

void Alumno::imprime(ofstream &arch){
    char buffN[50];
    GetNombre(buffN);
    
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(13)<<codigo<<setw(50)<<buffN<<right<<setw(3)<<" "<<escala<<
            setw(12)<<" "<<creditos;
}