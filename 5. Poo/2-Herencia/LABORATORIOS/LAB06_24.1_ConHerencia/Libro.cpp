
/* 
 * File:   Libro.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 21:55
 */
#include "Utils.h"
#include "Libro.h"
using namespace std;

Libro::Libro() {
    nombre = nullptr; 
    codigo = nullptr; 
    colocado = false; 
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    //asignamos memoria
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Libro::GetNombre(char *c) const {
    if(this->nombre==nullptr) c[0] = 0;
    else strcpy(c,this->nombre);
}

void Libro::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr) delete this->codigo;
    //asignamos memoria
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Libro::GetCodigo(char *c) const {
    if(this->codigo==nullptr) c[0] = 0;
    else strcpy(c,this->codigo);
}

void Libro::leer(ifstream &arch){
    char cod[10],nombre[60];
    int ancho,alto;
    arch.getline(cod,10,',');
    if(arch.eof())return;
    arch.getline(nombre,60,','); 
    arch>>ancho;
    arch.get();
    arch>>alto;
    arch.get(); //salto de linea 
    
    SetAlto(alto);
    SetAncho(ancho);
    SetCodigo(cod);
    SetNombre(nombre);
}

//SIN CABECERA 
void Libro::imprimir(ofstream &arch){
    char cod[20],nom[60];
    GetCodigo(cod);
    GetNombre(nom);
    if(IsColocado()){
        arch<<left<<setw(10)<<cod<<setw(25)<<nom<<right<<setw(4)<<GetAncho()
            <<setw(9)<<GetAlto()<<endl;
    }
    else{
        arch<<left<<setw(10)<<cod<<setw(25)<<"NO SE PUDO COLOCAR"<<right<<setw(4)
                <<GetAncho()<<setw(9)<<GetAlto()<<endl;
    }
}
    
