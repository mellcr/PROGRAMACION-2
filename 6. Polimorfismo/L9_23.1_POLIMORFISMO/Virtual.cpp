
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

void Virtual::lee(ifstream &arch){
    char buffL[15];
    
    Alumno::lee(arch);
    arch.getline(buffL,15);
    
    SetLicencia(buffL);
}

void Virtual::actualizatotal(double prec){\
    Alumno::actualizatotal(prec);
    int tot= Alumno::GetTotal();
    total = tot + 100.0;
    Alumno::SetTotal(total);
}

void Virtual::imprime(ofstream &arch){
    char buffL[50];
    GetLicencia(buffL);
    
    arch.precision(2);
    arch<<fixed;
    Alumno::imprime(arch);
    arch<<left<<setw(5)<<" "<<setw(10)<<buffL<<right<<setw(10)<<" "<<total<<endl;
}