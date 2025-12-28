
/* 
 * File:   Leve.cpp
 * Author: mell1
 * 
 * Created on 10 de junio de 2024, 22:53
 */
#include "Utils.h"
#include "Leve.h"
using namespace std;


Leve::Leve() {
}

Leve::~Leve() {
}

void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

