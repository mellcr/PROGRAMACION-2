/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Josue
 * 
 * Created on 13 de junio de 2024, 10:06 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Camion.h"

Camion::Camion() {
    ejes=0;
    llantas=0;
}
 
void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream &arch ){
    Vehiculo::lee(arch);
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();
}

void Camion::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<left<<setw(15)<<" "<<setw(16)<<"#Ejes:";
    arch<<right<<setw(8)<<ejes<<endl;
    arch<<left<<setw(15)<<" "<<setw(16)<<"#Llantas:";
    arch<<right<<setw(8)<<llantas<<endl;
    Vehiculo::imprimePedidos(arch);
}

