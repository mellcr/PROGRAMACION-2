/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include  "Utils.h"
#include "colaGenerica.h"
#include  "funciones.h"
using namespace std;

char *leeCadenaDelim(ifstream &arch, char delim){
    char *str, buff[100]; 
    arch.getline(buff,100,delim); 
    str = new char[strlen(buff)+1]; 
    strcpy(str,buff); 
    return str;
}

void *leeReg(ifstream &arch){
    void **registro = new void*[3]{};
    
    char *nombre,c; 
    int *edad = new int, *sueldo = new int; 
    nombre = leeCadenaDelim(arch,',');
    if(arch.eof()) return nullptr;
    arch>>*edad>>c>>*sueldo;
    arch.get(); 
    
    registro[NOMB] = nombre;
    registro[EDAD] = edad;
    registro[SUELDO] = sueldo;
    return registro; 
}

void creaColitaDobleEnlazada(void *&cola,const char *filename){
    ifstream arch(filename,ios::in); 
    if(not arch.is_open()){
        cout <<"no"; 
        exit(1); 
    }
    
    void *dato;
    inicializaCola(cola);
    
    while(true){
        dato = leeReg(arch);
        if(dato ==nullptr) break;
        
        encolaPrioridad_v2(cola,dato);
    }
}
    