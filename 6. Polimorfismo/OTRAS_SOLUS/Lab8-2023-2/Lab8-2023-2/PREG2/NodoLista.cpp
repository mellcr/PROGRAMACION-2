/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NodoLista.cpp
 * Author: Josue
 * 
 * Created on 13 de junio de 2024, 10:09 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "NodoLista.h"
#include "Furgon.h"
#include "Camion.h"
NodoLista::NodoLista() {
    unidad=nullptr;
    sig=nullptr;
}

//NodoLista::~NodoLista() {
//    if(unidad!=nullptr)delete unidad;
//}

void NodoLista::asignaMemoria(char tipo){
    if(tipo=='F'){
        unidad=new class Furgon;
    }else{
        unidad=new class Camion;
    }
}

void NodoLista::leeDatosCamiones(ifstream &arch){
    unidad->lee(arch);
}

void NodoLista::imprimeCamion(ofstream &arch){
    unidad->imprime(arch);
}

int NodoLista::getCod(){
    return unidad->GetCliente();
}

double NodoLista::getPesoSobrante(){
    return (unidad->GetMaxcarga() - unidad->GetActcarga());
}

void NodoLista::colocaPedido(int codCli,char *cadena,int cantidad,double peso){
    unidad->push(cadena,cantidad,peso);
}