/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* h
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 13 de junio de 2024, 09:38 AM
 */

#include "Flota.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Flota transporte;
    transporte.cargaflota();
    transporte.cargapedidos();
    transporte.muestracarga();
    return 0;
}

