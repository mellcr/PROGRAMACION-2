
/* 
 * File:   Falta.cpp
 * Author: mell1
 * 
 * Created on 10 de junio de 2024, 22:48
 */
#include "Utils.h"""
#include "Falta.h"
using namespace std;

Falta::Falta() {
    placa = nullptr;
}


Falta::~Falta() {
    if(placa) delete placa;
}

void Falta::SetPlaca(const char* placa) {
    if(this->placa!=nullptr) delete this->placa;
    this->placa = new char [strlen(placa)+1];
    strcpy(this->placa,placa);
}

void Falta::GetPlaca(char*c) const {
    if(this->placa==nullptr) c[0] = 0;
    else strcpy (c,this->placa);
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Falta::GetLicencia() const {
    return licencia;
}

