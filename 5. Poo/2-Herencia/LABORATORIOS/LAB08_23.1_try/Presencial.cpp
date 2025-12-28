
/* 
 * File:   Presencial.cpp
 * Author: mell1
 * 
 * Created on 25 de mayo de 2024, 20:59
 */

#include "Utils.h"
#include "Presencial.h"
#include "Alumno.h"
using namespace std; 

Presencial::Presencial() {
    recargo = 0.0;
    total = 0.0;
}

Presencial::~Presencial() {
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}


void Presencial::leerDatos(ifstream& arch){
    Alumno::leerDatos(arch); 
    arch>>recargo; //%
    arch.get(); //lee el salto de linea : ) 
}

void Presencial::actualiza(double monto){
    total = monto*recargo/100 ;     //monto por recarga 
    Alumno::SetTotal(monto+total); 
}

void Presencial::imprime(ofstream &arch){
    Alumno::imprime(arch); 
    arch<<right<<setw(15)<<"+"<<setw(10)<<Alumno::GetTotal()<<endl; 
}