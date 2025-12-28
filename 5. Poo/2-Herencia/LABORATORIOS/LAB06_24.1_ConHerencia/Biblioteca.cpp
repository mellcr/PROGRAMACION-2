
/* 
 * File:   Biblioteca.cpp
 * Author: mell1
 * 
 * Created on 31 de mayo de 2024, 4:05
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::cargar_libros(){
    ifstream arch("libros.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR AL ABRIR "<<"libros.csv"<<endl;
        exit(1);
    }
    while(true){
        libros[cantidad_libros].leer(arch); 
        if(arch.eof())break;
        cantidad_libros++;
    }
}

void Biblioteca::cargar_estantes(){
    
}

void Biblioteca::posicionar_libros(){
    
} 
    
void Biblioteca::mostrar_datos(){
    
} 