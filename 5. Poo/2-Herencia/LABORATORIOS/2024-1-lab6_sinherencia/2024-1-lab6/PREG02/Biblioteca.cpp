/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Josue
 * 
 * Created on 28 de mayo de 2024, 11:27 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
#include "Estante.h"
#include "Libro.h"
#define N 50 
Biblioteca::Biblioteca() {
    cantidad_estantes=0;
    cantidad_libros=0;
}

void Biblioteca::cargar_libros(){
    ifstream arch("libros.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR AL ABRIR "<<"libros.csv"<<endl;
        exit(1);
    }
    while(true){
        arch>>libros[cantidad_libros];
        if(arch.eof())break;
        cantidad_libros++;
    }
}

void Biblioteca::cargar_estantes(){
    ifstream arch("estantes.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR AL ABRIR "<<"estantes.csv"<<endl;
        exit(1);
    }
    while(true){
        arch>>estantes[cantidad_estantes];
        if(arch.eof())break;
        cantidad_estantes++;
    }
}

void Biblioteca::posicionar_libros(){
    for(int i=0;i<cantidad_libros;i++){
        for(int k=0;k<cantidad_estantes;k++){
            if(estantes[k]+=libros[i])break;
        }
    }
}

void Biblioteca::mostrar_datos(){
    ofstream arch("ReporteFinal.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR AL ABRIR "<<"ReporteFinal.txt"<<endl;
        exit(1);
    }
    imprimeLinea(arch,N,'=');
    arch<<setw(5)<<" "<<"Informacion del posicionamiento de Libros"<<endl;
    arch<<setw(10)<<" "<<"en los estantes de la Biblioteca"<<endl;
    imprimeLinea(arch,N,'=');
    for(int i=0;i<cantidad_estantes; i++){
        arch<<estantes[i];
        imprimeLinea(arch,N,'-');
    }
    arch<<endl;
    imprimeLinea(arch,N,'=');
    arch<<"Informacion de todos los Libros: "<<endl;
    arch<<"Cantidad de Libros Total: "<<cantidad_libros<<endl;
    for(int i=0; i<cantidad_libros; i++){
        arch<<libros[i];
    }
    imprimeLinea(arch,N,'=');
    
}

void Biblioteca::imprimeLinea(ofstream& arch, int n, char c) {
    for(int i=0; i<n; i++) arch.put(c);
    arch<<endl;
}


