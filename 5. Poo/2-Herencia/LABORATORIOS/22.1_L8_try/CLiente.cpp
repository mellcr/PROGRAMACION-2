
/* 
 * File:   CLiente.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 10:38
 */
#include "Utils.h"
#include "CLiente.h"
using namespace std; 

CLiente::CLiente() {
    dni = 0; 
}

CLiente::CLiente(const CLiente& orig) {
}

CLiente::~CLiente() {
}

void CLiente::SetNombre(const char* nombre) {
    if(this->nombre !=nullptr) delete this->nombre; 
    //creamos espacio dinamico 
    this->nombre = new char[strlen(nombre)+1]; 
    strcpy(this->nombre, nombre); 
}

void CLiente::GetNombre(char *c) const {
    if(this->nombre == nullptr) c[0] = 0; 
    else strcpy(c,this->nombre); 
}

void CLiente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char CLiente::GetCategoria() const {
    return categoria;
}

void CLiente::SetDni(int dni) {
    this->dni = dni;
}

int CLiente::GetDni() const {
    return dni;
}

/////
void CLiente::leer(ifstream &arch){
    char nomb[60],c; 
    
    arch>>dni; 
    //cout <<dni; 
    if(arch.eof()) return ; 
    arch.get(); 
    arch.getline(nomb,60,',');
    arch>>categoria; 
    
    SetNombre(nomb); 
    
} 