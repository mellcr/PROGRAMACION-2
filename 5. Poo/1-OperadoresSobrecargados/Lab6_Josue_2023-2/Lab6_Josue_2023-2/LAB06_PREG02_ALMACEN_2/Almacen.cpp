/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: Josue
 * 
 * Created on 23 de mayo de 2024, 12:14 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "Producto.h"
#include "Almacen.h"

Almacen::Almacen() {
    cantidad_clientes=0;
    cantidad_productos=0;
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::cargar_clientes(){
    ifstream arch("Clientes.csv",ios::in);
    if(not arch.is_open()){
        cout<<"Error:No se pudo abrir el archivo de clientes"<<endl;
        exit(1);
    }
    while(arch>>arreglo_cliente[cantidad_clientes]){
        cantidad_clientes++;
    }
}
void Almacen::cargar_productos(){
    ifstream arch("Productos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"Error:No se pudo abrir el archivo de productos"<<endl;
        exit(1);
    }
    while(arch>>arreglo_productos[cantidad_productos]){
       cantidad_productos++;
    }
    
}
void Almacen::cargar_pedidos(){
    ifstream arch("Pedidos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"Error:No se pudo abrir el archivo de pedidos"<<endl;
        exit(1);
    }
    class Pedido pedido;
    int posCliente,posProd;
    char cod[15];
    while(arch>>pedido){
        posCliente=buscarCliente(pedido.GetDni_cliente());
        if(posCliente!=-1){
            pedido.GetCodigo(cod);
            posProd=buscarProducto(cod);
            if(posProd!=-1){
                if(arreglo_productos[posProd]+=pedido){
                    arreglo_cliente[posCliente]+=pedido;
                }
            }
        }
    }
}

int Almacen::buscarCliente(int dni) {
    for (int i=0;i<cantidad_clientes;i++){
        if (arreglo_cliente[i].GetDni() == dni) return i;
    }
    return -1;
}

int Almacen::buscarProducto(const char* cod) {
    char codigo[20];
    for (int i=0;i<cantidad_productos;i++){
        arreglo_productos[i].GetCodigo(codigo);
        if (strcmp(cod, codigo) == 0) return i;
    }
    return -1;
}

void Almacen::mostrar_datos() {
    ofstream arch ("ReporteFinal.txt",ios::out);
    if (not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    arch << "REPORTE FINAL"<<endl;
    arch << setprecision(2)<<fixed;
    arch << "PRODUCTOS"<<endl;
    arch << left << setw(15)<<"CODIGO"<<setw(69)<<"DESCRIPCION"<<setw(12)
            <<"PRECIO"<<"STOCK"<<endl;
    for (int i=0;i<cantidad_productos;i++){
        arch << arreglo_productos[i];
        imprimeLinea ('-', arch);
    }
    imprimeLinea ('=', arch);
    arch << endl << "CLIENTES"<<endl;
    arch << left << setw(15)<<"DNI"<<setw(57)<<"NOMBRE"<<setw(11)<<"TELEFONO"
            <<"MONTO TOTAL"<<endl;
    for (int i=0;i<cantidad_clientes;i++){
        arch << arreglo_cliente[i];
        imprimeLinea ('-',arch);
    }
}

void Almacen::imprimeLinea(char c, ofstream& arch) {
    for (int i=0;i<100;i++) arch << c;
    arch << endl;
}

