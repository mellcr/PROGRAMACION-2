
/* 
 * File:   Categoria1.cpp
 * Author: mell1
 * 
 * Created on 19 de junio de 2024, 19:44
 */
#include "Utils.h"
#include "Categoria1.h"
using namespace std;

Categoria1::Categoria1() {
}

Categoria1::Categoria1(const Categoria1& orig) {
    *this = orig;
}

Categoria1::~Categoria1() {
}

void Categoria1::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria1::GetPrioridad() const {
    return prioridad;
}

void Categoria1::SetMinimo(int minimo) {
    this->minimo = minimo;
}

int Categoria1::GetMinimo() const {
    return minimo;
}

void Categoria1::leer(ifstream &arch){
    arch>>prioridad;
    arch.get();
    arch>>minimo;
    arch.get();
    Producto::leer(arch);
}

void Categoria1::imprime(ofstream &arch){
    arch<<setw(10)<<prioridad<<setw(10)<<minimo;
    Producto::imprime(arch);
}

int Categoria1::obtienePrio(){
    return prioridad; 
}