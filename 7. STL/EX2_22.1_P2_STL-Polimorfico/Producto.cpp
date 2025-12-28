
/* 
 * File:   Producto.cpp
 * Author: mell1
 * 
 * Created on 19 de junio de 2024, 19:40
 */
#include "Utils.h"
#include "Producto.h"
using namespace std;

Producto::Producto() {
    nombre = nullptr;
}

Producto::Producto(const Producto& orig) {
    nombre = nullptr;
    *this = orig;
}

Producto::~Producto() {
    if(this->nombre!=nullptr) delete this->nombre;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Producto::GetNombre(char*c) const {
    if(this->nombre==nullptr) c[0] = 0;
    strcpy(c,this->nombre);
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::leer(ifstream &arch){
    char c, nomb[100];
    arch>>codprod>>c;
    arch.getline(nomb,100,',');
    arch>>stock;
    
    SetNombre(nomb);
    
    //cout<<nomb<<endl;
}

void Producto::imprime(ofstream &arch){
    arch<<setw(10)<<codprod<<setw(50)<<nombre<<
            setw(10)<<stock<<endl;
}


