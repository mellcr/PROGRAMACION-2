/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 27 de abril de 2024, 16:28
 */

#include "Utils.h"
#include "funcionesVoid.h"
#include "funcionesCmp.h"
using namespace std;
#include <cstdlib> 
 



int main(int argc, char** argv) {
    /////////////////////////////////// registro (tipo void *) /////////////////////////////
    void *personal;
    int np;
    leerDatos(personal,np);
   
    imprimirDatos(personal,np);
    
    
    return 0;
}

