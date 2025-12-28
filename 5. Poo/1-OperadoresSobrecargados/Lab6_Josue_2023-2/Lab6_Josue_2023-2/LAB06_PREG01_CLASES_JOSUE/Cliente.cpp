/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Josue
 * 
 * Created on 22 de mayo de 2024, 11:12 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "ProductoEntregado.h"
#include "Pedido.h"

Cliente::Cliente() {
    nombre=nullptr;
    cantidad_productos_entregados=0;
    monto_total=0;
}

Cliente::Cliente(const Cliente& orig) {
    
}

Cliente::~Cliente() {
     if (nombre!=nullptr) delete nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(const char* nomb) {
    if(nombre!=nullptr)delete nombre;
    nombre=new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Cliente::GetNombre(char *nomb) const {
    if(nombre==nullptr)nomb[0]=0;
    else strcpy(nomb,nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator >>(ifstream &arch, class Cliente &cliente){
    int dni,telefono;
    char car,nomb[60];
    arch>>dni;
    if(arch.eof())return false;
    arch.get();
    arch.getline(nomb,60,',');
    arch>>telefono;
    cliente.SetDni(dni);
    cliente.SetTelefono(telefono);
    cliente.SetNombre(nomb);
    return true;
}

void Cliente::operator += (const class Pedido &pedido){
    char cod[10];
    double precio=pedido.GetPrecio_producto();
    pedido.GetCodigo(cod);
    productos_entregados[cantidad_productos_entregados].SetPrecio(precio);
    productos_entregados[cantidad_productos_entregados].SetCodigo(cod);
    cantidad_productos_entregados++;
    monto_total +=precio;
}
ofstream& operator << (ofstream &arch, const class Cliente &cli){
    char nomb[70];
    cli.GetNombre(nomb);
    arch << left <<setw(15) <<cli.GetDni()<<setw(50)<<nomb<<right << setw(15)
            <<cli.GetTelefono()<<setw(10)<<cli.GetMonto_total()<<endl;
    if (cli.GetCantidad_productos_entregados()==0)
        arch << "NO SE LE ENTREGARON PRODUCTOS";
    else{
        arch << "Productos entregados: ";
        cli.imprimirProductos (arch);
    }
    arch << endl;
    return arch;
}

void Cliente::imprimirProductos(ofstream &arch)const{
    char cod[20];
    for(int i=0;i<cantidad_productos_entregados;i++){
        productos_entregados[i].GetCodigo(cod);
        arch << left << setw(10)<< cod<<right;
    }
}
