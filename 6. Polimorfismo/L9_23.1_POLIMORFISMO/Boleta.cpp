
/* 
 * File:   Boleta.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 14:48
 */
#include "Utils.h"
#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
using namespace std;

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    if(pboleta!=nullptr) delete pboleta;
}

// ASIGNA MEMORIA AL PUNTERO DE ACUERDO A SU TIPO 
void Boleta::asignaMemoria(char tipo){
    if(tipo=='P'){
        pboleta = new class Presencial;
    }
    else if(tipo =='S'){
        pboleta = new class Semipresencial;
    }
    else if(tipo == 'V'){
        pboleta = new class Virtual;
    }
    
//    switch(tipo){
//        case 'P':
//            pboleta = new class Presencial;
//            break;
//        case 'S':
//            pboleta = new class Semipresencial;
//            break;
//        case 'V':
//            pboleta = new class Virtual;
//            break;
//    }
}

void Boleta::leeDatos(ifstream &arch){
    pboleta->lee(arch);
}

bool Boleta::hayDato(){
    if(pboleta!=nullptr) return true;
    else return false;
}

int Boleta::GetEscala(){
    return pboleta->GetEscala();
}

void Boleta::actualizaBoleta(double prec){
    pboleta->actualizatotal(prec);
}

void Boleta::imprimeBoleta(ofstream &arch){
    pboleta->imprime(arch);
}