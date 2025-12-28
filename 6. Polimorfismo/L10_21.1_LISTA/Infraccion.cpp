
/* 
 * File:   Infraccion.cpp
 * Author: mell1
 * 
 * Created on 10 de junio de 2024, 22:44
 */
#include "Utils.h"
#include "Infraccion.h"
using namespace std;

Infraccion::Infraccion() {
    gravedad = nullptr;
}


Infraccion::~Infraccion() {
    if(gravedad) delete gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(const char* gravedad) {
    if(this->gravedad!=nullptr) delete this->gravedad;
    this->gravedad = new char [strlen(gravedad)+1];
    strcpy(this->gravedad,gravedad);
}

void Infraccion::GetGravedad(char*c) const {
    if(this->gravedad==nullptr) c[0] = 0;
    else strcpy (c,this->gravedad);
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

