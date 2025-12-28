/* 
 * Proyecto: aprendiendoPunteroVoid
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 21 de abril de 2024, 12:12
 */

#include <iostream>
#include <iomanip> 
#include "funciones.h"
using namespace std;

//49087987,Adriana Vargas Perez, 987.97
int main(int argc, char** argv) {
    void *personas;
    int numPer;
    
    leeDatos(personas,numPer);
    ordenar(personas,0,numPer-1);
    imprimeDatos(personas,numPer);
    
    return 0;
}

