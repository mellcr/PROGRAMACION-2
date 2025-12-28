
/* 
 * File:   Pedido.cpp
 * Author: mell1
 * 
 * Created on 19 de junio de 2024, 19:37
 */
#include "Utils.h"
#include "Pedido.h"
using namespace std;

Pedido::Pedido() {
    
}

Pedido::Pedido(const Pedido& orig) {
    *this=orig;
}

Pedido::~Pedido() {
}

void Pedido::SetOrden(int orden) {
    this->orden = orden;
}

int Pedido::GetOrden() const {
    return orden;
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

void Pedido::lee(ifstream &arch){
    char c;
    int dia,mes,anho;
    
    arch>>codigo;
    if(arch.eof()) return;
    arch>>c>>cantidad>>c>>total>>c>>dni>>c>>dia>>c>>mes>>c>>anho;
    
    SetFecha(anho*100000+mes*100 + dia);
}

void Pedido::imprime(ofstream &arch){
    arch.precision(2); 
    arch<<fixed; 
    
    arch<<setw(10)<<fecha<<setw(10)<<codigo<<setw(10)<<cantidad
            <<setw(10)<<total;
    if(orden==1) arch<<setw(10)<<"Sí"<<endl;
    else arch<<setw(10)<<"No"<<endl;
}