/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Josue
 * 
 * Created on 13 de junio de 2024, 10:00 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Vehiculo.h"
#include "NPedido.h"
Vehiculo::Vehiculo() {
    ped=nullptr;
    placa=nullptr;
    actcarga=0;
}
 
Vehiculo::~Vehiculo() {
    if(ped!=nullptr)delete ped;
    if(placa!=nullptr)delete placa;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char* plac) {
    if(placa!=nullptr)delete placa;
    placa=new char[strlen(plac)+1];
    strcpy(placa,plac);
}

void Vehiculo::GetPlaca(char* plac) const {
    if(placa==nullptr)plac[0]=0;
    else strcpy(plac,placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream &arch ){
    arch>>cliente;
    arch.get();
    char cadena[15];
    arch.getline(cadena,15,',');
    SetPlaca(cadena);
    arch>>maxcarga;
    arch.get();
}

void Vehiculo::imprime(ofstream &arch){
    arch<<left<<setw(15)<<" "<<setw(16)<<"Codigo Cliente:";
    arch<<right<<setw(8)<<cliente<<endl;
    arch<<left<<setw(15)<<" "<<setw(16)<<"Placa:";
    arch<<right<<setw(8)<<placa<<endl;
    arch<<left<<setw(15)<<" "<<setw(16)<<"Carga Maxima:";
    arch<<right<<setw(8)<<maxcarga<<endl;
    arch<<left<<setw(15)<<" "<<setw(16)<<"Carga Actual:";
    arch<<right<<setw(8)<<actcarga<<endl;
}

void Vehiculo::imprimePedidos(ofstream &arch){
    char codigo[8];
    if(ped==nullptr){
        arch<<left<<setw(15)<<" "<<setw(16)<<"No hay pedidos para el cliente"<<endl;
        arch<<endl;
    }else{
        arch<<left<<setw(15)<<" "<<setw(16)<<"Pedidos:"<<endl;
        NPedido *recorrido;
        recorrido=ped;
        while(recorrido){
            recorrido->GetCodigo(codigo);
            arch<<left<<setw(18)<<" "<<setw(8)<<codigo;
            arch<<right<<setw(5)<<recorrido->GetCantidad();
            arch<<setw(10)<<recorrido->GetPeso()<<endl;
            recorrido=recorrido->sig;
        }
        arch<<endl;
    }
}

void Vehiculo::push(char *codPedido,int cantidad,double peso){
    class NPedido *nuevoNodo=new class NPedido;
    nuevoNodo->asignaDatos(codPedido,cantidad,peso);
    if(pilavacia()){
        ped=nuevoNodo;
    }
    else{
        nuevoNodo->sig=ped;
        ped=nuevoNodo;
    }
    actcarga+=peso;
}

bool Vehiculo::pilavacia(){
    if(ped==nullptr) return true;
    else return false;
}