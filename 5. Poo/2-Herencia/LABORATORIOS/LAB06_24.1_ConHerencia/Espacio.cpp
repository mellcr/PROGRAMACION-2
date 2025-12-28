
/* 
 * File:   Espacio.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 22:03
 */
#include "Utils.h"
#include "Espacio.h"
using namespace std;

Espacio::Espacio() {
    contenido= ' ';
}

Espacio::Espacio(const Espacio& orig) {
}

Espacio::~Espacio() {
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

//

void Espacio::imprimir(ofstream &arch){
    if(contenido==' '){
        arch<<"[  ]";
    }
    else{
        arch<<"[ * ]";
    }
}