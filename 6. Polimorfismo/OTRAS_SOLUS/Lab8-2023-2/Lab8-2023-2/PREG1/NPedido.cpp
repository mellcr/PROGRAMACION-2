/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NPedido.cpp
 * Author: Josue
 * 
 * Created on 13 de junio de 2024, 09:55 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "NPedido.h"

NPedido::NPedido() {
    codigo=nullptr;
    sig=nullptr;
    cantidad=0;
}

NPedido::~NPedido() {
    if(codigo!=nullptr)delete codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(const char* cod) {
    if(codigo!=nullptr)delete codigo;
    codigo=new char [strlen(cod)+1];
    strcpy(codigo,cod);
}

void NPedido::GetCodigo(char* cod) const {
    if(codigo==nullptr)cod[0]=0;
    else strcpy(cod,codigo);
}

