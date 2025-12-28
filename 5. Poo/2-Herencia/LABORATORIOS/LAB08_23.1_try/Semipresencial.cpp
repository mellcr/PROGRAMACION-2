
/* 
 * File:   Semipresencial.cpp
 * Author: mell1
 * 
 * Created on 28 de mayo de 2024, 15:12
 */

#include "Utils.h"
#include "Semipresencial.h"
#include "Alumno.h"
using namespace std; 

Semipresencial::Semipresencial() {
    descuento = 0; 
    total = 0;
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

void Semipresencial::leerDatos(ifstream &arch){
    Alumno::leerDatos(arch); 
    arch>>descuento; 
    arch.get(); //lee el salto de linea : ) 
}

void Semipresencial::actualiza(double monto){
    total = monto*descuento/100 ;     //monto por recarga 
    Alumno::SetTotal(monto+total); 
}

void Semipresencial::imprime(ofstream &arch){
    Alumno::imprime(arch); 
    arch<<right << setw(15)<<"-"<<setw(10)<<Alumno::GetTotal()<<endl; 
}