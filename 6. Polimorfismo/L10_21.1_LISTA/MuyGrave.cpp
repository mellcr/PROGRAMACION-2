
/* 
 * File:   MuyGrave.cpp
 * Author: mell1
 * 
 * Created on 10 de junio de 2024, 22:58
 */
#include "Utils.h"
#include "MuyGrave.h"
using namespace std;

MuyGrave::MuyGrave() {
}


MuyGrave::~MuyGrave() {
}

void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

