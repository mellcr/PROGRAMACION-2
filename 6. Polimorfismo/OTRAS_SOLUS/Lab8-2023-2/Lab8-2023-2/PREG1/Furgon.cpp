/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: Josue
 * 
 * Created on 13 de junio de 2024, 10:07 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Furgon.h"

Furgon::Furgon() {
    puertas=0;
    filas=0;
}
 
void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(ifstream &arch ){
    Vehiculo::lee(arch);
    arch>>filas;
    arch.get();
    arch>>puertas;
    arch.get();    
  
}

void Furgon::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<left<<setw(15)<<" "<<setw(16)<<"#Filas:";
    arch<<right<<setw(8)<<filas<<endl;
    arch<<left<<setw(15)<<" "<<setw(16)<<"#Puertas:";
    arch<<right<<setw(8)<<puertas<<endl;
    Vehiculo::imprimePedidos(arch);
}