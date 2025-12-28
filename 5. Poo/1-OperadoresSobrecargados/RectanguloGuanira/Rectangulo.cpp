

/* 
 * File:   Rectangulo.cpp
 * Author: mell1
 * 
 * Created on 19 de mayo de 2024, 14:50
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Rectangulo.h"
using namespace std;

//Dentro de esta funcion tengo acceso directo a los atributos
void Rectangulo::setBase(double b){
    base = b;
}

void Rectangulo::setAltura(double a){
    altura = a;
}

double Rectangulo::getBase(){
    return base;
}

double Rectangulo::getAltura(){
    return altura;
}

double Rectangulo::area(){
    return altura*base;
}

double Rectangulo::perimetro(){
    return 2*altura+ 2*base;
}

void Rectangulo::leeDatos(){
    ifstream arch("Datos.txt",ios::in);
//    int b,a;
//    arch>>b>>a;
//    setAltura(a);
//    setBase(b);
    
    arch>>base>>altura;
}
void Rectangulo::muestraDatos(){
    cout.precision(2);
    cout<<fixed;
    
    cout<<left<<setw(15)<<"Base: "<<setw(10)<<right<<base<<endl;
    cout<<left<<setw(15)<<"Altura: "<<setw(10)<<right<<altura<<endl;
}
    
void Rectangulo::mostrarResultados(){
    //dentro de una func se puede usar los privados
    //Sin embargo, no es conveniente hacerlo 
//    Rectangulo instancia1;
//    instancia1.altura=7;
    
    
    cout.precision(2);
    cout<<fixed;
    
    muestraDatos();
    cout<<left<<setw(15)<<"Area: "<<setw(10)<<right<<area()<<endl;
    cout<<left<<setw(15)<<"Perimetro: "<<setw(10)<<right<<perimetro()<<endl;
}