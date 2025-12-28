
/* 
 * File:   Sinreceta.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 12:47
 */
#include "Utils.h"
#include "Sinreceta.h"
using namespace std; 

Sinreceta::Sinreceta() {
    nombre = nullptr; 
}

Sinreceta::Sinreceta(const Sinreceta& orig) {
}

Sinreceta::~Sinreceta() {
    if(nombre) delete nombre; 
}

void Sinreceta::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre; 
    //le damos espacio
    this->nombre = new char[strlen(nombre)+1]; 
    strcpy(this->nombre,nombre); 
}

void Sinreceta::GetNombre(char *c) const {
    if(this->nombre==nullptr) c[0] = 0; 
    else strcpy(c,this->nombre); 
}

void Sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int Sinreceta::GetDni() const {
    return dni;
}

void Sinreceta::leer(int dniCli,char *nombCli,int codMedicam,int cant,
                       int fecha){
    char nomb[60];
    double prec;
    
    dni = dniCli;
    SetNombre(nombCli);
    Medicamento::SetCodigo(codMedicam); 
    Medicamento::SetCantidad(cant); 
    Medicamento::SetFecha(fecha); 
    
    //los obtiene pero tmb los setea en la funcion
    Medicamento::GetNombYPrecioEnArchivo(codMedicam,nomb,prec);
    SetPrecio(prec);
    SetNombre(nomb);
}

void Sinreceta::imprime(ofstream &arch){
    Medicamento::imprime(arch);
    arch<<right<<setw(10)<<dni<<left<<setw(5)<<" "<<setw(50)
            <<nombre<<endl;
}
    