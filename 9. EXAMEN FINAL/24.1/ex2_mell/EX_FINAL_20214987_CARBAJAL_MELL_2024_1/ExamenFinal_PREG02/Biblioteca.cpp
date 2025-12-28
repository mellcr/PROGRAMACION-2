/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 10:33 AM
 */
#include "Utils.h"
using namespace std;
#include "Biblioteca.h"
#include "Libro.h"
#include "Autor.h"


Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::cargar_libros(const char *filename){
    ifstream arch(filename,ios::in); 
    if(!arch.is_open()){
        cout <<"pipip"<<endl; 
        exit(1);
    }
    
    
    while(true){
        class Libro lib;
        lib.leeDatos(arch); 
        if(arch.eof()) return; 
        //anadimos al vetor 
        libros.push_back(lib); 
    }
}

void Biblioteca::cargar_autores(const char *filename){
    ifstream arch(filename,ios::in); 
    if(!arch.is_open()){
        cout <<"pipip"<<endl; 
        exit(1);
    }
    
    while(true){
        class Autor aut; 
        aut.leeDatos(arch); 
        if(arch.eof()) return; 
        
        autores[aut.GetCodigo()] = aut; 
    }
    
}
void Biblioteca::cargar_clientes(const char *filename){
    ifstream arch(filename,ios::in); 
    if(!arch.is_open()){
        cout <<"pipip"<<endl; 
        exit(1);
    }
    
    
}
void Biblioteca::mostrar_recomendaciones(const char *filename){
    ofstream arch(filename,ios::out); 
    if(!arch.is_open()){
        cout <<"pipip"<<endl; 
        exit(1);
    }
}
    