
/* 
 * File:   Consumible.cpp
 * Author: mell1
 * 
 * Created on 25 de mayo de 2024, 16:50
 */
#include "Utils.h"
#include "Consumible.h"
using namespace std;

Consumible::Consumible() {
}

Consumible::Consumible(const Consumible& orig) {
}

Consumible::~Consumible() {
}


void Consumible::setIncremento(int incremento) {
    this->incremento = incremento;
}

int Consumible::getIncremento() const {
    return incremento;
}