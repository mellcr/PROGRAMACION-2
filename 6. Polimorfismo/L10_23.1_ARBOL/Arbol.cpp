
/* 
 * File:   Arbol.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 22:26
 */
#include "Utils.h"
#include "Arbol.h"
using namespace std;

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    //llama a un metodo eliminar :) 
}

void Arbol::crear(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout << "no se abrio "<<endl;
        exit(1);
    }
    
    class Boleta dato; //DATO DEL NODO 
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        
        dato.asignaMemoria(tipo);
        dato.leeDatos(arch);
        
        insertarRec(raiz,dato);
    }
    dato.SetNull();
}

//insertar en orden recursivo :) 
void Arbol::insertarRec(class Nodo *&arbol,const class Boleta &dato){
    //CASO BASE 
    if(arbol==nullptr){
        //creamos Nodo
        arbol = new class Nodo;
        arbol->dboleta = dato; //son punteros 
        //arbol->dboleta.imprimeCod();
        return;
    }
    
    if(arbol->dboleta > dato){
        insertarRec(arbol->izq,dato);
    }
    else{
        insertarRec(arbol->der,dato);
    }
}

void Arbol::imprimirEnOrden(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout << "no se abrio "<<endl;
        exit(1);
    }
    imprimirEnOrdenRec(arch,raiz);
}

// I - R - D
void Arbol::imprimirEnOrdenRec(ofstream &arch, class Nodo *arbol){
    if(arbol){
        imprimirEnOrdenRec(arch,arbol->izq);
        arch<<arbol->dboleta;  // sobrecarga
        //arbol->dboleta.imprimeCod();
        imprimirEnOrdenRec(arch,arbol->der);
    }
}