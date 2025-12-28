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
    void *persona;
    
    leeRegistro(persona);
    imprimeRegistro(persona);
    liberaEspacios(persona);
    //cuando la estructura es mas grande... 
    persona = leeRegistro();
    imprimeRegistro(persona);
    
    return 0;
}

