
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

void Presencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch>>recargo;
    arch.get();
    
    //cout <<recargo<<endl;
}

void Presencial::actualizatotal(double prec){
    Alumno::actualizatotal(prec);
    
    int tot= Alumno::GetTotal();
    total = tot + (tot*(recargo/100.0));
    Alumno::SetTotal(total);
}

void Presencial::imprime(ofstream &arch){
    arch.precision(2);
    arch<<fixed;
    
    Alumno::imprime(arch);
    arch<<right<<setw(25)<<" "<<total<<endl;
}