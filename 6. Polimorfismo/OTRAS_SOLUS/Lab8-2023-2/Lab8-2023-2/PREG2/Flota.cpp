/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Josue
 * 
 * Created on 13 de junio de 2024, 10:12 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Flota.h"

void Flota::cargaflota(){
    ifstream arch("Vehiculos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DE Vehiculos.csv"<<endl;
        exit(1);
    }
    lista.leeVehiculos(arch);
}

void Flota::muestracarga(){
    ofstream arch("reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"Error: no se puede abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    arch<<setw(25)<<" "<<"REPORTE DE FLOTA"<<endl;
    for(int i=0;i<60;i++)arch.put('=');
    arch<<endl;
    lista.imprimeVehiculos(arch);
}

void Flota::cargapedidos(){
    ifstream arch("Pedidos3.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DE Pedidos3.csv"<<endl;
        exit(1);
    }
    lista.leePedido(arch);
}

