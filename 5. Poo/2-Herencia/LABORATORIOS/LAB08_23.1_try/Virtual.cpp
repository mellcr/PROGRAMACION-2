
/* 
 * File:   Virtual.cpp
 * Author: mell1
 * 
 * Created on 28 de mayo de 2024, 15:15
 */
#include "Utils.h"
#include "Virtual.h"
#include "Alumno.h"
using namespace std; 

Virtual::Virtual() {
    licencia = nullptr; 
    total = 100.0; //100 es el valor de la licencia 
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
    if(this->licencia) delete this->licencia;
    //se separa mem
    this->licencia = new char [strlen(licencia)+1];
    strcpy(this->licencia,licencia);
}

void Virtual::GetLicencia(char *c) const {
    if(this->licencia==nullptr) c[0] = 0;
    else strcpy(c,this->licencia);
}

void Virtual::leerDatos(ifstream& arch){
    char buffLicencia[20]; 
    Alumno::leerDatos(arch); 
    
    arch.getline(buffLicencia,20); 
    SetLicencia(buffLicencia); 
}

void Virtual::actualiza(double monto){
    Alumno::SetTotal(monto+total);  //montoCred + total(100) 
}
    
void Virtual::imprime(ofstream &arch){
    Alumno::imprime(arch); 
    arch<<right << setw(15)<<licencia<<setw(10)<<Alumno::GetTotal()<<endl; 
}