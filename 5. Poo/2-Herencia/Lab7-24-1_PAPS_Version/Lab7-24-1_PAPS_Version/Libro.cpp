
                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Libro.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

Libro::Libro(){
    codigo = nullptr;
    nombre = nullptr;
    ancho = 0;
    alto = 0;
    colocado = false;
}
//Libro::Libro(const Libro &origen){
//}
//Libro::~Libro(){
//    if(codigo!=nullptr) delete codigo;
//    if(nombre!=nullptr) delete nombre;
//    ancho = 0;
//    alto = 0;
//    colocado = false;
//}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::GetColocado() const {
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
    if(this->nombre!=nullptr)   delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Libro::GetNombre(char*nombre) const {
    if(this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Libro::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr)   delete this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Libro::GetCodigo(char*codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}

void Libro::leeLibro(ifstream &arch){
    char codigo[8],nombre[100],c;
    int ancho,alto;
    arch.getline(codigo,8,',');
    if(arch.eof())return;
    arch.getline(nombre,50,',');
    arch>>ancho>>c>>alto>>c;
    SetCodigo(codigo);
    SetNombre(nombre);
    SetAncho(ancho);
    SetAlto(alto);
}

void Libro::muestraLibro(ofstream &arch){
    char codigo[8],nombre[100];
    GetCodigo(codigo);
    GetNombre(nombre);
    if(colocado)
        arch<<left<<setw(11)<<codigo<<setw(35)<<nombre<<setw(8)<<ancho<<setw(8)<<alto;
    else
        arch<<left<<setw(11)<<codigo<<setw(35)<<"NO SE PUDO COLOCAR"<<setw(8)<<ancho<<setw(8)<<alto<<endl;
}

                    /* CODEANDO CON PAPS */