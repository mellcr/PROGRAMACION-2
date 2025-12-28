/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 09:37 AM
 */
#include "Utils.h"
using namespace std; 
#include "Pila.h"
#include "Ejemplar.h"

Pila::Pila() {
    nelementos = 0; 
    pcima = nullptr; 
}

Pila::Pila(const Pila& orig) {
}

Pila::~Pila() {
}



void Pila::setNelementos(int nelementos) {
    this->nelementos = nelementos;
}

int Pila::getNelementos() const {
    return nelementos;
}

 bool Pila::pilaVacia(){
     if(pcima==nullptr){
         return true; 
     }else return false; 
 }

void Pila::apilar(class Ejemplar*&dato){
    //creamos nuevo nodo 
    class Ejemplar *nuevo = new Ejemplar; 
    nuevo = dato; 
    
    //primer dato
    if(pilaVacia()){
        pcima = nuevo; 
    }
    else{
        //apilamos encima 
        class Ejemplar *primero = pcima; 
        nuevo->sig = primero;
        pcima =  nuevo; 
    }
    nelementos++;
}

void Pila::desapilar(){
    class Ejemplar *desapilado; 
    
    cout<<pcima->plibro->GetPeso();
    //nelementos--;
}