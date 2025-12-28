/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 10:27 AM
 */
#include "Utils.h"
using namespace std; 
#include "Cliente.h"

Cliente::Cliente() {
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::SetCantidad_libros_comprados(int cantidad_libros_comprados) {
    this->cantidad_libros_comprados = cantidad_libros_comprados;
}

int Cliente::GetCantidad_libros_comprados() const {
    return cantidad_libros_comprados;
}

void Cliente::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Cliente::GetNombre() const {
    return nombre;
}

void Cliente::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Cliente::GetCodigo() const {
    return codigo;
}

