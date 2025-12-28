/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejemplar.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 09:36 AM
 */
#include "Utils.h"
using namespace std; 
#include "Ejemplar.h"
#include "Novela.h"
#include "Revista.h"

Ejemplar::Ejemplar() {
    plibro = nullptr; 
    sig = nullptr; 
}

Ejemplar::Ejemplar(const Ejemplar& orig) {
    
}

Ejemplar::~Ejemplar() {
}

void Ejemplar::asignaMem(char tipo){
    if(tipo=='N'){
        plibro = new class Novela; 
    }
    else { //R
        plibro = new class Revista; 
    }
}
void Ejemplar::leeEjemplares(ifstream &arch){
    plibro->lee(arch); 
}

