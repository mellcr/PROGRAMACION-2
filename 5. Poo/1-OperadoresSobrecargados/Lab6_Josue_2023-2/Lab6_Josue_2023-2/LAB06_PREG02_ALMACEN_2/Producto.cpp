/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Josue
 * 
 * Created on 23 de mayo de 2024, 12:02 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Producto.h"

Producto::Producto() {
    stock=0;
    cantidad_clientes_no_servidos=0;
    cantidad_clientes_servidos=0;
    codigo=nullptr;
    descripcion=nullptr;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
 
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(const char* desc) {
    if(descripcion!=nullptr)delete descripcion;
    descripcion=new char [strlen(desc)+1];
    strcpy(descripcion,desc);
}

void Producto::GetDescripcion(char *desc) const {
    if(descripcion==nullptr)desc[0]=0;
    else strcpy(desc,descripcion);
}

void Producto::SetCodigo(const char* cod) {
        if(codigo!=nullptr)delete codigo;
    codigo=new char [strlen(cod)+1];
    strcpy(codigo,cod);
}

void Producto::GetCodigo(char *cod) const {
    if(codigo==nullptr)cod[0]=0;
    else strcpy(cod,codigo);
}

bool operator >> (ifstream &arch, class Producto &producto){
    char cod[10],descrpcion[70];
    double precio;
    int stockIni;
    arch.getline(cod,10,',');
    if(arch.eof())return false;
    arch.getline(descrpcion,70,',');
    arch>>precio;
    arch.get();
    arch>>stockIni;
    arch.get();
    producto.SetCodigo(cod);
    producto.SetStock(stockIni);
    producto.SetPrecio(precio);
    producto.SetDescripcion(descrpcion);
    return true;
}

bool Producto::operator +=( class Pedido &pedido){
    pedido.SetPrecio_producto(precio);
    if(stock>0){
        clientes_servidos[cantidad_clientes_servidos]=pedido.GetDni_cliente();
        stock--;
        cantidad_clientes_servidos++;
       return true;
    }
    else{
        clientes_no_servidos[cantidad_clientes_no_servidos]=pedido.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }
}

ofstream & operator <<(ofstream &arch,const class Producto &prod){
    char cod[20], desc[70];
    prod.GetCodigo(cod);
    prod.GetDescripcion(desc);
    arch << left << setw(15)<<cod << setw(60)<<desc<<right << setw(15)
            <<prod.GetPrecio() << setw(10)<<prod.GetStock()<<endl;
    prod.imprimeAtendidos(arch);
    prod.imprimeNoAtendidos(arch);
    return arch;
}

void Producto::imprimeAtendidos(ofstream &arch)const {
    if (cantidad_clientes_servidos == 0){
        arch << "NO SE ATENDIERON PEDIDOS"<<endl;
        return;
    }
    arch << "Clientes atendidos:";
    for (int i=0;i<cantidad_clientes_servidos;i++)
        arch << right << setw(12)<<clientes_servidos[i];
    arch << endl;
}

void Producto::imprimeNoAtendidos(ofstream &arch)const{
    if (cantidad_clientes_no_servidos == 0){
        arch << "NO HAY CLIENTES SIN ATENDER"<<endl;
        return;
    }
    arch << "Clientes no atendidos:";
    for (int i=0;i<cantidad_clientes_no_servidos;i++)
        arch << right << setw(12)<<clientes_no_servidos[i];
    arch << endl;
}

