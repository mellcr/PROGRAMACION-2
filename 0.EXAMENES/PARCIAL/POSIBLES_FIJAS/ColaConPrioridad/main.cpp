/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 11 de mayo de 2024, 13:08
 */

#include <iostream>
#include <fstream>
#include <iostream>
#include "ColaGenerica.h"
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    void *cola;
    inicializaCola(cola); 
    colitaCreadaPorNosotros(cola,"DatosPrioridad.txt");
    imprimeColaPri(cola,"PruebaColaPri.txt");
    return 0;
}

