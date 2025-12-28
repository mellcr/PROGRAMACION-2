
/* 
 * File:   Medico.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 12:38
 */
#include "Utils.h"
#include "Medico.h"
using namespace std; 

Medico::Medico() {
    especialidad = nullptr; 
    nombre = nullptr; 
}

Medico::Medico(const Medico& orig) {
}

Medico::~Medico() {
    if(especialidad) delete especialidad; 
    if(nombre) delete nombre; 
}

void Medico::SetEspecialidad(const char* especialidad) {
    if(this->especialidad!=nullptr) delete this->especialidad; 
    //le damos espacio
    this->especialidad = new char[strlen(especialidad)+1]; 
    strcpy(this->especialidad,especialidad); 
}

void Medico::GetEspecialidad(char *c) const {
    if(this->especialidad==nullptr) c[0] = 0; 
    else strcpy(c,this->especialidad); 
}

void Medico::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre; 
    //le damos espacio
    this->nombre = new char[strlen(nombre)+1]; 
    strcpy(this->nombre,nombre); 
}

void Medico::GetNombre(char *c) const {
    if(this->nombre==nullptr) c[0] = 0; 
    else strcpy(c,this->nombre);
}

void Medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medico::GetCodigo() const {
    return codigo;
}

//50611,EDGAR  MUNOZ VERGEL,Urologia
void  Medico::leer(ifstream &arch){
    char nomb[60], espc[60]; 
    
    arch>>codigo; 
    if(arch.eof()) return; 
    arch.get();
    arch.getline(nomb,60,','); 
    arch.getline(espc,60); //hasta el salto de linea
    
    SetEspecialidad(espc); 
    SetNombre(nomb); 
}