
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


void Semipresencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::actualizatotal(double prec){
    Alumno::actualizatotal(prec);
    
    int tot= Alumno::GetTotal();
    total = tot - (tot*(descuento/100.0));
    Alumno::SetTotal(total);
}


void Semipresencial::imprime(ofstream &arch){
    arch.precision(2);
    arch<<fixed;
    
    Alumno::imprime(arch);
    arch<<right<<setw(25)<<" "<<total<<endl;
}