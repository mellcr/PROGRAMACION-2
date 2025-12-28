/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Josue
 * 
 * Created on 28 de mayo de 2024, 11:22 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"
#include "Espacio.h"
#include "Estante.h"
#define N 50
Estante::Estante() {
    codigo=nullptr;
    espacios=nullptr;
    cantidad_libros=0;
}


Estante::~Estante() {
    if(codigo!=nullptr)delete codigo;
    if(espacios!=nullptr)delete []espacios;
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* cod) {
    if(codigo!=nullptr)delete codigo;
    codigo=new char [strlen(cod)+1];
    strcpy(codigo,cod);
}

void Estante::GetCodigo(char* cod) const {
    if(codigo==nullptr)cod[0]=0;
    else strcpy(cod,codigo);
}

void Estante::creaEspacios(){
    int anch=0,alt=0;
    if(anchura!=0 and altura!=0){
        espacios=new class Espacio[anchura*altura];
        for(int i=0;i<anchura*altura;i++){
            
            espacios[i].SetPosx(alt);
            espacios[i].SetPosy(anch);
            anch++;
           
            if(anch==anchura){
                anch=0;
                alt++;
            }
        }
        
    }
    
}

int Estante::calcularEspaciosLibres(){
    int sumaAnchLib=0;
    for(int i=0; i<cantidad_libros; i++){
        sumaAnchLib+=libros[i].GetAncho();
    }
    return anchura-sumaAnchLib;
}

bool Estante::operator +=(class Libro &libro){
    int espacioLibre=calcularEspaciosLibres(),altoLibro,anchoLibro,anc,alt;
    altoLibro=libro.GetAlto();
    anchoLibro=libro.GetAncho();
    if(anchoLibro<=espacioLibre and altoLibro<=altura and espacioLibre>0){
        colocarLibro(altoLibro,anchoLibro,espacioLibre);
        char nom[60],cod[20];
        libro.GetCodigo(cod);
        libro.GetNombre(nom);
        libros[cantidad_libros].SetNombre(nom);
        libros[cantidad_libros].SetAlto(libro.GetAlto());
        libros[cantidad_libros].SetAncho(libro.GetAncho());
        libros[cantidad_libros].SetCodigo(cod);
        libros[cantidad_libros].SetColocado(true);
        cantidad_libros++;
        libro.SetColocado(true);
        return true;
    }
    else{
        return false;
    }
}

void Estante::colocarLibro(int altLibro,int ancLibro, int sobrante){
    int posLibro=anchura*altura - sobrante;
    for(int i=0;i<altLibro;i++){
        for(int k=0;k<ancLibro;k++){
            espacios[posLibro+k].SetContenido('*');
        }
        
        posLibro-=anchura;
    }
}

void Estante::imprimeLibros(ofstream& arch) const {
    arch<<left<<setw(10)<<"CODIGO"<<setw(25)<<"NOMBRE"<<setw(10)<<"ANCHO"<<"ALTO"<<endl;
    for(int i=0; i<N; i++)arch.put('.');
    arch<<endl;
    for(int i=0; i<cantidad_libros; i++){
        arch<<libros[i];
    }
    arch<<endl;
}

void Estante::imprimeEspacios(ofstream& arch) const {
    for(int i=0; i<anchura*altura; i++){
        arch<<espacios[i];
        if(espacios[i].GetPosy()==anchura-1)arch<<endl;
    }
}

ifstream & operator >>(ifstream &arch,class Estante &estante){
    char codigo[10];
    int altura,anchura;
    arch.getline(codigo,10,',');
    if(arch.eof())return arch;
    arch>>anchura;
    arch.get();
    arch>>altura;
    arch.get(); 
    estante.SetAltura(altura);
    estante.SetAnchura(anchura);
    estante.SetCodigo(codigo);
    estante.creaEspacios();
    return arch;
}

void operator <<(ofstream &arch,const class Estante &est){
    char cod[20];
    est.GetCodigo(cod);
    arch<<left<<setw(15)<<"Codigo Estante: "<<setw(10)<<
            cod<<"Cantidad de Libros: "<<setw(5)<<est.GetCantidad_libros()<<endl;
    arch<<left<<setw(20)<<"Anchura del Estante: "
            <<setw(5)<<est.GetAnchura()<<"Altura del Estante: "<<est.GetAltura()<<endl;
    for(int i=0; i<N; i++)arch.put('-');
    arch<<endl;
    est.imprimeEspacios(arch);
    est.imprimeLibros(arch);
}