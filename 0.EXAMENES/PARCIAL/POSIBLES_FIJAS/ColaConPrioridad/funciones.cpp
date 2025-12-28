/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "ColaGenerica.h"
#define MAXBLANC 20
using namespace std;
enum Registro{NOMB,EDAD,SUELDO};

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


void colitaCreadaPorNosotros(void *&cola,const char *filename){
    ifstream arch(filename,ios::in); 
    if(not arch.is_open()){
        cout <<"no"; 
        exit(1); 
    }
    void *dato;
    
    while(true){
        dato  = leeReg(arch);
        if(dato ==nullptr) break; 
        
        encolaPrioridad(cola,dato); 
    }
    
}

//enum Registro{NOMB,EDAD,SUELDO};
void imprimeColaPri(void *cola,const char *filename){
    ofstream arch(filename,ios::out); 
    if(not arch.is_open()){
        cout <<"no"; 
        exit(1); 
    }
    
    void **castCola = (void **)cola; 
    while(not colavacia(cola)){
        void *dato = desencola(cola); 
        void **registro = (void **)dato; 
        char *nomb = (char *)registro[NOMB];
        int *edad = (int *)registro[EDAD];
        int *sueldo = (int *)registro[SUELDO];
        
        arch<<left<<nomb<<setw(MAXBLANC-strlen(nomb))<<" "<<right<<*edad<<setw(10)<<*sueldo<<endl;
        
    }
}