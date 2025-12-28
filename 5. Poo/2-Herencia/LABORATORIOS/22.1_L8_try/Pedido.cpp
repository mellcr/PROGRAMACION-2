
/* 
 * File:   Pedido.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 10:42
 */
#include "Utils.h"
#include "Pedido.h"
using namespace std; 

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetObs(const char* obs) {
    if(this->obs !=nullptr) delete this->obs; 
    //creamos espacio dinamico 
    this->obs = new char[strlen(obs)+1]; 
    strcpy(this->obs, obs); 
}

void Pedido::GetObs(char *c) const {
    if(this->obs == nullptr) c[0] = 0; 
    else strcpy(c,this->obs); 
}


void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::leer(ifstream &arch){
    char c; 
    int dia,mes,anho; 
    
    arch>>codigo; 
    if(arch.eof()) return; 
    arch>>c>>cantidad>>c>>dni>>c>>dia>>c>>mes>>c>>anho; 
    arch.get();  //lee el salto de linea 
    
    SetFecha(100000*anho+100*mes+dia); 
    Producto::asignaProducto(codigo); 
    
    double prec = GetPrecio(); 
    SetTotal(cantidad*prec); 
    //cout <<prec<<" ";
}

void  Pedido::muestra(ofstream &arch){
    //cout <<"Dri"<<endl; 
    char nombProd[60], obsProd[60]; 
    GetNombre(nombProd); 
    GetObs(obsProd); 
    
    arch<<left<<setw(15)<<fecha<<setw(15)<<codigo<<
            setw(60)<<nombProd<<right<<setw(4)<<
            cantidad<<setw(10)<<GetPrecio()<<setw(10)<<
            total<<left<<"  "<<setw(50)<<obsProd<<endl;
    
}

void Pedido::agregaDescuento(char categoria){
    if(categoria=='A'){
        total = total*0.5; 
        SetObs("Descuento Especial de 50%");
    }
    else if(categoria=='B'){
        total = total*0.7; 
        SetObs("Descuento Especial de 30%");
    }
    else if(categoria=='C'){
        total = total*0.9;  
        SetObs("Descuento Especial de 10%");
    }
}