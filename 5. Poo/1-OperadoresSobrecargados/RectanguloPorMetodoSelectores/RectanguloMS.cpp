
/* 
 * File:   RectanguloMS.cpp
 * Author: mell1
 * 
 * Created on 19 de mayo de 2024, 17:05
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "RectanguloMS.h"
using namespace std;

RectanguloMS::RectanguloMS(const RectanguloMS& orig) {
    char n[100]; 
    orig.getNombre(n); 
    setNombre(n);
    setBase(orig.getBase()); 
    setAltura(orig.getAltura()); 
}


RectanguloMS::RectanguloMS() { //por defecto
    inicializa(); //lo llamamos pq ya lo tenemos
    base = 0; 
    altura = 0; 
}
RectanguloMS::RectanguloMS(double b, double h, const char*n){
    setNombre(n);
    setBase(b); 
    setAltura(h); 
}

//puede tener cualquier cosa 
RectanguloMS::~RectanguloMS() {
    elimina();
}

//Dentro de esta funcion tengo acceso directo a los atributos

double RectanguloMS::getBase()const{
    return base;
}

double RectanguloMS::getAltura()const{
    return altura;
}

void RectanguloMS::setBase(double b){
    this->base = b;
}

void RectanguloMS::setAltura(double a){
    this->altura = a;
}



double RectanguloMS::area(){
    return altura*base;
}

double RectanguloMS::perimetro(){
    return 2*altura+ 2*base;
}

void RectanguloMS::leeDatos(){
    ifstream arch("Datos.txt",ios::in);
    
    arch>>this->base>>this->altura;
}
void RectanguloMS::muestraDatos(){
    cout.precision(2);
    cout<<fixed;
    
    cout<<left<<setw(15)<<"Base: "<<setw(10)<<right<<base<<endl;
    cout<<left<<setw(15)<<"Altura: "<<setw(10)<<right<<altura<<endl;
}
    
void RectanguloMS::mostrarResultados(){
    cout.precision(2);
    cout<<fixed;
    
    cout<<"Nombre: "<<nombre<<endl;
    muestraDatos();
    cout<<left<<setw(15)<<"Area: "<<setw(10)<<right<<area()<<endl;
    cout<<left<<setw(15)<<"Perimetro: "<<setw(10)<<right<<perimetro()<<endl;
}

// REFACTOR -> ENCAPSULATED FIELDS 
void RectanguloMS::setNombre(const char* cad) {
    //cuando se quiere actualizar, se debe deletear el antiguo
    if(nombre!=nullptr) delete nombre; 
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
    
    
    //this->nombre = nombre; //punt = punt {? no , apuntarian al mismo sitio
}

//no puede devolver char* pq le estaria dando al usuario el control del atributo
void RectanguloMS::getNombre(char *cad) const {
    strcpy(cad,nombre);
    //return nombre; // devuelve una copia de la direc de la cad -> no es correcto
}

void RectanguloMS::inicializa(){
    nombre = nullptr;
}


void RectanguloMS::elimina(){
    //solo se necesita deletear el nombre
    delete nombre;
}

//CONSTRUCTOR POR PARAMETROS 
