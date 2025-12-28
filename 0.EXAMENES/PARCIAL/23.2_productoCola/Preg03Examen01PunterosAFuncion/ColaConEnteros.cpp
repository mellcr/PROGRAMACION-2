/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "funcUtils.h"
#include "ColaConEnteros.h"
#include "ColaGenerica.h"
using namespace std;\

void *leenumero(ifstream &arch){
    int num;
    arch>>num;
    if(arch.eof()) return nullptr;
            
    int *numero = new int;
    *numero = num;
    
    return numero;
}


void cargaEnteros(void *&cola,void *(*leenumero)(ifstream &),const char *filename){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout <<"no";
        exit(1);
    }
    //aux e inicializamos cola
    generacola(cola); 
    void *dato;
    
    
    while(true){
        dato = leenumero(arch);
        if(dato==nullptr) break; 
        
        encola(cola,dato);
    }
    
}

void mostrarEnteros(void *cola,void (*imprime)(void *dato, ofstream &arch),const char *filename){
    ofstream arch(filename,ios::out);
    if(not arch.is_open()){
        cout <<"no";
        exit(1);
    }
    void **colaCast = (void **)cola; 
    void **rec = (void **)colaCast[CAB]; 
    
    while(rec){
        imprime(rec[DAT], arch); 
        rec = (void **)rec[SIG]; 
    }
    
}

void imprimenumero(void *dato, ofstream &arch){
    int *datoEnt = (int *)dato; 
    arch <<*datoEnt<<endl;
}