
/* 
 * File:   Arbol.cpp
 * Author: mell1
 * 
 * Created on 8 de junio de 2024, 20:34
 */
#include "Utils.h"
#include "Arbol.h"
#include "Nodo.h"
using namespace std;

Arbol::Arbol() {
    arbol = nullptr;
}


Arbol::~Arbol() {
    elimina(arbol);
}

void Arbol::elimina(class Nodo *rec){
    if(rec){
        elimina(rec->izq);
        elimina(rec->der);
        delete rec;
    }
}
 
void Arbol::crear(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout <<"no se abrio "<<filename;
        exit(1);
    }
    
    class Persona dato;
    while(true){
        arch>>dato;
        if(arch.eof())break;
        
        //insertar(dato);
        insertaRec(arbol,dato);
    }
}

void Arbol::insertar(const class Persona &dato){
    insertaRec(arbol,dato);
}

void Arbol::insertaRec(class Nodo *&arbol,const class Persona &dato){
    if(arbol==nullptr){
        //crear nodo
        arbol = new class Nodo;
        arbol->dato = dato; // sobrecarga
        return; 
    }
    //dato menor -> izq  |  dato mayor -> der 
    if(arbol->dato > dato) insertaRec(arbol->izq,dato);
    else insertaRec(arbol->der,dato);
}

void Arbol::mostrarEnOrden(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout <<"no se abrio "<<filename;
        exit(1);
    }
    //if(arbol!=nullptr)cout<<arbol->dato.GetDni()<<endl;
    mostrarOrdenRec(arbol,arch);
    arch<<endl;
}

void Arbol::mostrarOrdenRec(class Nodo *arbol, ofstream &arch){
    if(arbol){
        mostrarOrdenRec(arbol->izq,arch);
        //cout<<arbol->dato.GetDni()<<endl;
        arch <<arbol->dato;
        mostrarOrdenRec(arbol->der,arch);
    }
}

class Persona Arbol::buscar(int dni){
    return buscarRec(arbol,dni);
}

class Persona Arbol::buscarRec(class Nodo *arbol,int dni){
    class Persona p;
    int d;
    
    p.SetDni(-1);
    if(arbol==nullptr) return p;
    
    if(arbol->dato.GetDni() ==dni) return arbol->dato;
    d = arbol->dato.GetDni();
    
    if(d>dni) return buscarRec(arbol->izq,dni);
    else return buscarRec(arbol->der,dni);
}