
/* 
 * File:   Ciudad.cpp
 * Author: mell1
 * 
 * Created on 8 de julio de 2024, 10:42 p. m.
 */

#include "Ciudad.h"

Ciudad::Ciudad() {
}

Ciudad::Ciudad(const Ciudad& orig) {
    *this = orig;
}

Ciudad::~Ciudad() {
}

void Ciudad::SetCord_y(double cord_y) {
    this->cord_y = cord_y;
}

double Ciudad::GetCord_y() const {
    return cord_y;
}

void Ciudad::SetCord_x(double cord_x) {
    this->cord_x = cord_x;
}

double Ciudad::GetCord_x() const {
    return cord_x;
}

void Ciudad::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Ciudad::GetNombre() const {
    return nombre;
}

void Ciudad::leer(ifstream &arch){
    char c;
    
    getline(arch,nombre,',');
    if(arch.eof()) return;
    arch>>cord_x>>c>>cord_y;
    arch.get();
}
void Ciudad::mostra(ofstream &arch) const{
    arch<< GetNombre()<<" ("<<GetCord_x()<<" , "<<GetCord_y()<<")"<<endl;
}
void Ciudad::mostra() const{
    cout<< GetNombre()<<" ("<<GetCord_x()<<" , "<<GetCord_y()<<")"<<endl;
}