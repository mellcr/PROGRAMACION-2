
/* 
 * File:   NProductos.cpp
 * Author: mell1
 * 
 * Created on 19 de junio de 2024, 19:49
 */
#include "Utils.h"
#include "NProductos.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"
using namespace std;

NProductos::NProductos() {
    prod = nullptr;
}

NProductos::NProductos(const NProductos& orig) {
    
    //PUNTERO -> solo asignar 
    this->prod = orig.prod;
}

NProductos::~NProductos() {
    //if(prod!= nullptr ) delete this->prod; 
}

void NProductos::leeproductos(ifstream &arch){
    int cat;
    arch>>cat;
    if(arch.eof()) return;
    arch.get();
    //reserva de memoria
    if(cat==1)
        prod = new class Categoria1;
    if(cat==2)
        prod = new class Categoria2;
    if(cat==3)
        prod = new class Categoria3;
    // lee polimorficamente
    prod->leer(arch);
}

void NProductos::imprimeproductos(ofstream &arch){
    prod->imprime(arch);
}

void NProductos::getPriYCodProd(int &prio, int &cod){
    cod  = prod->GetCodprod(); 
    prio = prod->obtienePrio();  
}


