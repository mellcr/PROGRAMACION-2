
/* 
 * File:   Producto.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 10:41
 */
#include "Utils.h"
#include "Producto.h"
using namespace std; 

Producto::Producto() {
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetNombre(const char* nombre) {
    if(this->nombre !=nullptr) delete this->nombre; 
    //creamos espacio dinamico 
    this->nombre = new char[strlen(nombre)+1]; 
    strcpy(this->nombre, nombre); 
}

void Producto::GetNombre(char *c) const {
    if(this->nombre == nullptr) c[0] = 0; 
    else strcpy(c,this->nombre); 
}




void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}
void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

///
void Producto::asignaProducto(int cod ){
    ifstream archProd("productos3.txt",ios::in); 
    if(not archProd.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1); 
    }
    
    char nomb[60],c;
    int codLeido; 
    
    while(true){
        archProd>>codLeido; 
        if(archProd.eof()) break;
        if(cod==codLeido){
            archProd.get(); 
            archProd.getline(nomb,60,','); 
            archProd>>precio>>c>>stock; 
            
            SetCodprod(codLeido);
            SetNombre(nomb); 
        }
        else while(archProd.get()!='\n'); 
    }
    SetCodprod(0); 
}

