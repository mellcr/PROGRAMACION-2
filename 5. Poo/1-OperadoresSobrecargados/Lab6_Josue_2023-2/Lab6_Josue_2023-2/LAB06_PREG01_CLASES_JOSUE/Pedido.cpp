/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Josue
 * 
 * Created on 23 de mayo de 2024, 12:08 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    codigo=nullptr;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if(codigo!=nullptr)delete codigo;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char* cod) {
    if(codigo!=nullptr)delete codigo;
    codigo=new char [strlen(cod)+1];
    strcpy(codigo,cod);
}

void Pedido::GetCodigo(char *cod) const {
    if(codigo==nullptr)cod[0]=0;
    else strcpy(cod,codigo);
}

bool operator >>(ifstream &arch, class Pedido &pedido){
    char cod[10];
    int dni;
    arch.getline(cod,10,',');
    if(arch.eof())return false;
    arch>>dni;
    arch.get();
    pedido.SetDni_cliente(dni);
    pedido.SetCodigo(cod);
    return true;
}