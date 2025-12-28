
/* 
 * File:   Categoria3.cpp
 * Author: mell1
 * 
 * Created on 19 de junio de 2024, 19:48
 */
#include "Utils.h"
#include "Categoria3.h"
using namespace std;

Categoria3::Categoria3() {
}

Categoria3::Categoria3(const Categoria3& orig) {
    *this = orig;
}

Categoria3::~Categoria3() {
}

void Categoria3::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria3::GetDescuento() const {
    return descuento;
}

void Categoria3::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria3::GetPrioridad() const {
    return prioridad;
}

void Categoria3::leer(ifstream &arch){
    char c;
    arch>>prioridad>>c>>descuento>>c;
    Producto::leer(arch);
}

void Categoria3::imprime(ofstream &arch){
    arch<<setw(10)<<prioridad<<setw(10)<<descuento;
    Producto::imprime(arch);
}

int Categoria3::obtienePrio(){
    return GetPrioridad(); 
}
