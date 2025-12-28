
/* 
 * File:   Pokeball.cpp
 * Author: mell1
 * 
 * Created on 25 de mayo de 2024, 16:22
 */
#include "Utils.h"
#include "Pokeball.h"
using namespace std;

Pokeball::Pokeball() {
    
}

Pokeball::Pokeball(const Pokeball& orig) {
}

Pokeball::~Pokeball() {
}

void Pokeball::setRatio(double ratio) {
    this->ratio = ratio;
}

double Pokeball::getRatio() const {
    return ratio;
}

void Pokeball::mostrar(){
    cout<<"Clase Derivada"<<endl;
    char nombre[50],descripcion[50];
    GetNombre(nombre);
    GetDescripcion(descripcion);
    cout<<setw(20)<<nombre;
    cout<<setw(50)<<descripcion<<endl;
}