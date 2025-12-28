
/* 
 * File:   Conreceta.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 12:44
 */
#include "Utils.h"
#include "Conreceta.h"
using namespace std; 

Conreceta::Conreceta() {
    especialidad = nullptr; 
}

Conreceta::Conreceta(const Conreceta& orig) {
}

Conreceta::~Conreceta() {
    if(especialidad) delete especialidad; 
}

void Conreceta::SetEspecialidad(const char* especialidad) {
    if(this->especialidad!=nullptr) delete this->especialidad; 
    //le damos espacio
    this->especialidad = new char[strlen(especialidad)+1]; 
    strcpy(this->especialidad,especialidad); 
}

void Conreceta::GetEspecialidad(char *c) const {
    if(this->especialidad==nullptr) c[0] = 0; 
    else strcpy(c,this->especialidad); 
}

void Conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int Conreceta::GetCodmed() const {
    return codmed;
}

//
void Conreceta::leer(int codMedico, int codMedicam,int cant,
        int fecha, char *buffEspc){
    
    char nomb[60];
    double prec;
    //cout <<codMedicam<<endl;
    Medicamento::SetCodigo(codMedicam); 
    Medicamento::SetCantidad(cant); 
    Medicamento::SetFecha(fecha); 
    codmed = codMedico; 
    SetEspecialidad(buffEspc);// -> del medico 
    //cout<<buffEspc<<endl;
    //los obtiene pero tmb los setea en la funcion
    Medicamento::GetNombYPrecioEnArchivo(codMedicam,nomb,prec);
    GetNombre(nomb);
//    SetPrecio(prec);
//    SetNombre(nomb);
    
    cout<<codMedicam<<" "<<nomb<<" "<<codMedico<<" "<<endl;
    
}

void Conreceta::imprime(ofstream &arch){
    Medicamento::imprime(arch);
//    arch<<right<<setw(10)<<codmed<<left<<setw(5)<<" "<<setw(50)
//            <<especialidad<<endl;
}