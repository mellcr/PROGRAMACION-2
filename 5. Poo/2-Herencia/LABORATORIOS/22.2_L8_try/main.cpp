
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 12:31
 */

#include "Utils.h"
#include "Farmacia.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Farmacia ofarma; 
    
    ofarma.cargamedido(); 
    ofarma.leerecetas(); 
    ofarma.imprimirrecetas();
    
    return 0;
}

