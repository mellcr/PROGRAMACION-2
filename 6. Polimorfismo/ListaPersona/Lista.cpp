
/* 
 * File:   Lista.cpp
 * Author: mell1
 * 
 * Created on 8 de junio de 2024, 13:06
 */
#include <algorithm>

#include "Utils.h"
#include "Lista.h"
using namespace std;

Lista::Lista() {
    lista = nullptr;
}

//Lista::Lista(const Lista& orig) {
//}

Lista::~Lista() {
    elimina();
}

void Lista::elimina(){
    class Nodo *eliminado;
    while(lista){
        eliminado = lista;
        lista = lista->sig;
        delete eliminado;
    }
    lista = nullptr;
}

void Lista::crear(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout <<"no se abrio "<<filename;
        exit(1);
    }
    // lee del archivo
    class Persona dato;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        insertar(dato);
    }
}

// INSERTA ORDENADO :) 
void Lista::insertar(const class Persona &dato){
    class Nodo *rec = lista, *ptAnt = nullptr, *nuevo;
    //crearNodo
    nuevo = new class Nodo;
    nuevo->dato = dato;
    //iterativa para llegar al lugar dnde insertar en orden (ASC - de menor a mayor)
    while(rec){
        if(rec->dato > dato) break;
        ptAnt = rec;
        rec = rec->sig;
    }
    nuevo->sig = rec;
    if(ptAnt!=nullptr) ptAnt->sig = nuevo;
    else lista = nuevo; 
}

void Lista::imprimirIterativo(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout <<"no se abrio "<<filename;
        exit(1);
    }
    
    class Nodo *rec = lista;
    arch<<"Datos de la lista: "<<endl;
    while(rec){
        arch<<rec->dato;
        rec = rec->sig;
    }
    arch<<endl;
}

void Lista::imprimirRec(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout <<"no se abrio "<<filename;
        exit(1);
    }
    imprimeRecursivo(arch,lista);
    arch<<endl;
}

void Lista::imprimeRecursivo(ofstream &arch,class Nodo *rec){
    if(rec==nullptr) return;
    imprimeRecursivo(arch,rec->sig);
    arch<<rec->dato;
}
    
