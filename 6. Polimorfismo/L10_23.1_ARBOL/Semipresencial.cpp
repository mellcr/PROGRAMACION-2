
/* 
 * File:   Semipresencial.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 14:42
 */
#include "Utils.h"
#include "Semipresencial.h"
using namespace std;

Semipresencial::Semipresencial() {
    total =0.0;
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void  Semipresencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch>>descuento;
    arch.get();
}

void  Semipresencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    
    arch.precision(2);
    arch<<fixed;
    arch<<setw(5)<<" "<<left<<setw(10)<<" "<<right<<setw(10)<<total<<endl;
    double var = descuento;
}