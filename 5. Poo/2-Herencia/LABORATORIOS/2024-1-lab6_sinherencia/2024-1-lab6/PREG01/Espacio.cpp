/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Espacio.cpp
 * Author: Josue
 * 
 * Created on 28 de mayo de 2024, 11:20 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Espacio.h"

Espacio::Espacio() {
    contenido=' ';
}

void Espacio::SetPosy(int posy) {
    this->posy = posy;
}

int Espacio::GetPosy() const {
    return posy;
}

void Espacio::SetPosx(int posx) {
    this->posx = posx;
}

int Espacio::GetPosx() const {
    return posx;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}



void operator <<(ofstream &arch,const class Espacio &esp){
    if(esp.GetContenido()==' '){
        arch<<"[   ]";
    }
    else arch<<"[ * ]";
}


