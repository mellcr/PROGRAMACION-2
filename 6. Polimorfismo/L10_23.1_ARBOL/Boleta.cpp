
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

void Boleta::SetNull(){
    pboleta = nullptr;
}

void Boleta::asignaMemoria(char tipo){
    if(tipo=='P') pboleta = new class Presencial;
    if(tipo=='S') pboleta = new class Semipresencial;
    if(tipo=='V') pboleta = new class Virtual;
}
    
void Boleta::leeDatos(ifstream &arch){
    pboleta->lee(arch);
}

//arbol->dboleta > dato
bool Boleta::operator > (const class Boleta &dato){
    int cod1,cod2;
    cod1=pboleta->GetCodigo();
    cod2 = dato.pboleta->GetCodigo();
    
    return cod1 > cod2;
}

//arbol->dboleta = dato; //son punteros
//void Boleta::operator =(const class Boleta&dato){
//    pboleta = dato.pboleta;
//}



void operator <<(ofstream &arch,const class Boleta &boleta){
    boleta.imprimeDatos(arch);
}

void Boleta::imprimeDatos(ofstream &arch)const {
    pboleta->imprime(arch);
}

void Boleta::imprimeCod(){
    cout<<pboleta->GetCodigo()<<endl;
}