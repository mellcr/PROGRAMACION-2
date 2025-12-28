
/* 
 * File:   Categoria2.cpp
 * Author: mell1
 * 
 * Created on 19 de junio de 2024, 19:46
 */
#include "Utils.h"
#include "Categoria2.h"
using namespace std;


Categoria2::Categoria2() {
}

Categoria2::Categoria2(const Categoria2& orig) {
    *this = orig;
}

Categoria2::~Categoria2() {
}

void Categoria2::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria2::GetDescuento() const {
    return descuento;
}

void Categoria2::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria2::GetPrioridad() const {
    return prioridad;
}

void Categoria2::leer(ifstream &arch){
    char c;
    arch>>prioridad>>c>>descuento>>c;
    Producto::leer(arch);
}


void Categoria2::imprime(ofstream &arch){
    arch<<setw(10)<<prioridad<<setw(10)<<descuento;
    Producto::imprime(arch);
}

int Categoria2::obtienePrio(){
    return prioridad; 
}
