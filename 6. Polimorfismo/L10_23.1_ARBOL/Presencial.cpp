
/* 
 * File:   Presencial.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 14:40
 */

#include "Utils.h"
#include "Presencial.h"
#include "Alumno.h"
using namespace std;

Presencial::Presencial() {
    total =0.0;
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

void  Presencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch>>recargo;
    arch.get();
}

void  Presencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    
    arch.precision(2);
    arch<<fixed;
    arch<<setw(5)<<" "<<left<<setw(10)<<" "<<right<<setw(10)<<total<<endl;
    
    double var = recargo;
}