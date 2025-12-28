
/* 
 * File:   Escala.cpp
 * Author: mell1
 * 
 * Created on 25 de mayo de 2024, 20:41
 */
#include "Utils.h"
#include "Escala.h"
using namespace std; 

Escala::Escala() {
    codigo = 0;
    precio =0.0;
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

///////////////////////////// EXTRAS /////////////////////////////
//void Escala::leeEscala(ifstream &arch){
//    arch>>codigo;
//    if(arch.eof()) 
//    arch.get(); 
//    arch>>precio; 
//}