
/* 
 * File:   Virtual.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 14:43
 */
#include "Utils.h"
#include "Virtual.h"
using namespace std;

Virtual::Virtual() {
    licencia = nullptr;
    total =0.0;
}


Virtual::~Virtual() {
    if(licencia) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* licencia) {
    if(this->licencia!=nullptr) delete this->licencia;
    this->licencia = new char [strlen(licencia)+1];
    strcpy(this->licencia,licencia);
}

void Virtual::GetLicencia(char*c) const {
    if(this->licencia==nullptr) c[0] = 0;
    else strcpy(c,this->licencia);
}

void  Virtual::lee(ifstream &arch){
    char buff[50];
    
    Alumno::lee(arch);
    arch.getline(buff,50);
    
    SetLicencia(buff);
}

void  Virtual::imprime(ofstream &arch){
    char buff[50];
    GetLicencia(buff);
    
    Alumno::imprime(arch);
    arch.precision(2);
    arch<<fixed;
    arch<<setw(5)<<" "<<left<<setw(10)<<buff<<right<<setw(10)<<total<<endl;
    double tot=total;
}