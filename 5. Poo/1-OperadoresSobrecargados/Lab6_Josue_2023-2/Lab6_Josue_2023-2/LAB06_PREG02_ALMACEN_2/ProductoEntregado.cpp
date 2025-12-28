/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ProductoEntregado.cpp
 * Author: Josue
 * 
 * Created on 22 de mayo de 2024, 10:47 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo=nullptr;
    precio=0.0;
}

ProductoEntregado::ProductoEntregado(const ProductoEntregado& orig) {
}

ProductoEntregado::~ProductoEntregado() {
    if (codigo!=nullptr) delete codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char* cod) {
    if(codigo!=nullptr)delete codigo;
    codigo=new char [strlen(cod)+1];
    strcpy(codigo,cod);
}

void ProductoEntregado::GetCodigo(char *cod) const {
    if(codigo==nullptr)cod[0]=0;
    else strcpy(cod,codigo);
}

