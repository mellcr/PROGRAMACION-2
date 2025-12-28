
/* 
 * File:   Grave.cpp
 * Author: mell1
 * 
 * Created on 10 de junio de 2024, 22:56
 */
#include "Utils.h"
#include "Grave.h"
using namespace std;

Grave::Grave() {
}

Grave::~Grave() {
}

void Grave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Grave::GetPuntos() const {
    return puntos;
}

void Grave::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Grave::GetDescuento() const {
    return descuento;
}

