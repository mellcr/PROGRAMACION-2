/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "funcUtils.h"
#include "ColaGenerica.h"
using namespace std;

//enum Cola{CAB,COLA,TOTALPED};
void generacola(void *&cola){
    int *total = new int;
    *total = 0;
    //inicializamos
    void **colaCast = (void **)cola;
    colaCast[CAB] = nullptr;
    colaCast[COL] = nullptr;
    colaCast[TOTALPED] = total;
}

bool colaVacia(void *cola){
    void **colaCast = (void **)cola;
    if(colaCast[CAB] ==nullptr and colaCast[COL] ==nullptr) return true;
    return false; 
}

//enum Cola{CAB,COLA,TOTALPED};
//enum Nodo{DAT, SIG};
//enum Dato{FECHA,DNI,CANT};
void encola(void *&cola, void *dato){
    void **colaCast = (void **)cola;
    void **datoCast = (void **)dato;
    
    void **nuevoNodo = new void*[2]{};
    nuevoNodo[DAT] = dato;
    nuevoNodo[SIG] = nullptr; //sera el ult elem
    
    if(colaVacia(cola)){
        colaCast[CAB] = nuevoNodo;
        colaCast[COL] = nuevoNodo;
    }else{
        void **nodoCola = (void **)colaCast[COL];
        nodoCola[SIG] = nuevoNodo;
        colaCast[COL] = nuevoNodo;
    }
}

//  DESENCOLA EL PRIMER ELEMENTOS
void *desencola(void *&cola){
    void **colaCast = (void **)cola;
    void *elemento;
    
    //1. APUNTAR AL PRIUMER ELEM
    void **primerNodo = (void **)colaCast[CAB];
    
    if(primerNodo[SIG]==nullptr){ //solo hay un elemento
        elemento = primerNodo[DAT];
        colaCast[CAB] = nullptr;
        colaCast[COL] = nullptr;
    }else {
        elemento = primerNodo[DAT];
        colaCast[CAB] = primerNodo[SIG];
    }
    
    delete primerNodo;
    return elemento;
}