/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   LVehiculos.cpp
 * Author: Josue
 * 
 * Created on 13 de junio de 2024, 10:11 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "LVehiculos.h"
#include "NodoLista.h"
LVehiculos::LVehiculos() {
    lini=nullptr;
    lfin=nullptr;
}

void LVehiculos::leeVehiculos(ifstream &arch){
    char tipo;
    
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        insertaNodo(arch,tipo);
    }
    
}

void LVehiculos::insertaNodo(ifstream &arch,char tipo){
    class NodoLista *nuevoNodo=new class NodoLista;
    nuevoNodo->asignaMemoria(tipo);
    nuevoNodo->leeDatosCamiones(arch);
    if(lini==nullptr){
        lini=nuevoNodo;
        lfin=nuevoNodo;
    }
    else{
        lfin->sig=nuevoNodo;
        lfin=nuevoNodo;
    }
}

void LVehiculos::imprimeVehiculos(ofstream &arch){
    class NodoLista *aux;
    aux=lini; 
    while(aux){
        aux->imprimeCamion(arch);
        aux=aux->sig;
    }
}

void LVehiculos::leePedido(ifstream &arch){
    int cantidad,codCli;
    double peso;
    char cadena[10];
    while(true){
        arch>>codCli;
        if(arch.eof())break;
        arch.get();
        arch.getline(cadena,10,',');
        arch>>cantidad;
        arch.get();
        arch>>peso;
        colocaPedido(codCli,cadena,cantidad,peso);
    }
}

void LVehiculos::colocaPedido(int codCli,char *cadena,int cantidad,double peso){
    class NodoLista *aux;
    aux=lini;
    while(aux){
        if(codCli == aux->getCod() ){
            if(peso<=aux->getPesoSobrante()){
                aux->colocaPedido(codCli,cadena,cantidad,peso);
            }
        }
        aux=aux->sig;
    }
 }
