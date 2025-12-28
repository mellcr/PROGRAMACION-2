
/* 
 * File:   Persona.cpp
 * Author: mell1
 * 
 * Created on 8 de junio de 2024, 12:57
 */
#include "Utils.h"
#include "Persona.h"
using namespace std;
Persona::Persona() {
    nombre = nullptr;
}

Persona::Persona(const Persona& orig) {
    nombre = nullptr;
    *this = orig;
}

Persona::~Persona() {
    if(nombre) delete nombre;
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Persona::GetNombre(char *c) const {
    if(this->nombre==nullptr) c[0] = 0;
    else strcpy(c,this->nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

//378708,SAENZ ARANDA WILMER,23455.6
ifstream &operator >>(ifstream &arch, class Persona &dato){
    int dni;
    double sueldo;
    char nomb[50],c;
    
    arch>>dni;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(nomb,50,',');
    arch>>sueldo;
    
    dato.SetDni(dni);
    dato.SetSueldo(sueldo);
    dato.SetNombre(nomb);
    
    return arch;
}

ofstream &operator <<(ofstream &arch, const class Persona &dato){
    char buffN[50];
    dato.GetNombre(buffN);
    
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(10)<<dato.GetDni()<<setw(50)<<buffN<<right<<setw(10)
            <<dato.GetSueldo()<<endl;
}

//persona::                         const class Persona p
//noTieneNada(nuevoNodo)            tieneDatos-> es lo que he leido
//nuevo->dato(persona)      =       dato(pesona);
void Persona::operator =(const class Persona &p){
    char buffN[50];
    p.GetNombre(buffN);
    
    dni = p.dni;
    sueldo = p.sueldo;
    SetNombre(buffN);
    
}

// persona::         p
//rec->dato (per) > dato(per)
bool Persona::operator >(const class Persona&p){
    char buffN[50];
    p.GetNombre(buffN);
    return dni > p.dni;
    //return strcmp(nombre,buffN)>0;
}