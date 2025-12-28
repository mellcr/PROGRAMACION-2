
                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Espacio.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

Espacio::Espacio(){
    contenido = ' ';
    posx = 0;
    posy = 0;
}
//Espacio::Espacio(const Espacio &origen){
//}
//Espacio::~Espacio(){
//    contenido = ' ';
//    posx = 0;
//    posy = 0;
//}

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
void Espacio::muestraEspacio(ofstream &arch){
    arch<<"["<<contenido<<"]";
}
                    /* CODEANDO CON PAPS */