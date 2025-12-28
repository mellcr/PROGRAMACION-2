
/* 
 * File:   Escala.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 14:37
 */
#include "Utils.h"
#include "Escala.h"
using namespace std;

Escala::Escala() {
}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}



