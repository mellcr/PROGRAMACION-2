
/* 
 * File:   Lista.cpp
 * Author: mell1
 * 
 * Created on 19 de junio de 2024, 19:54
 */

#include "Utils.h"
#include "Lista.h"
using namespace std;

Lista::Lista() {
    lfin = nullptr;
    lini = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::leerPedidos(ifstream &arch){
    class Pedido *ped;
    
    while(true){
        ped = new class Pedido; //asigna memoria
        ped->lee(arch);
        if(arch.eof()) break;
        //cout<<ped->GetFecha()<<endl;
        insertarOrden(ped); //insertamos
    }
}

void Lista::insertarOrden(class Pedido *&dato){
    class Nodo *rec = lini,*ant=nullptr, *nuevo;
    nuevo = new class Nodo;
    nuevo->ped = dato;
    
    //1. recorro hasta la posicion a insertar
    while(rec){
        if(rec->ped->GetFecha() > dato->GetFecha()) break;
        ant = rec;
        rec = rec->sig;
    }
    // 1. asignamos nuevo nodo
    nuevo->sig = rec;
    nuevo->ant = ant;
    //REC
    if(rec==nullptr) lfin = nuevo;
    else rec->ant = nuevo;
    //ANTERIOR
    if(ant!=nullptr) ant->sig = nuevo;
    else lini = nuevo; //cabeza
}

void Lista::imprimeDatos(ofstream &arch){
    arch<<endl<<setw(50)<<"REPORTE DE PEDIDOS"<<endl; 
    for(int i=0; i<100; i++) arch<<'=';
    arch<<endl;
    imprimirIterativo(arch); 
}

void Lista::imprimirIterativo(ofstream &arch){
    class Nodo *rec = lini;
    //arch<<"Datos de la lista: "<<endl;
    while(rec){
        rec->ped->imprime(arch);
        rec = rec->sig;
    }
    arch<<endl;
}

void Lista::actualizaOrden(int prio, int cod){
    class Nodo *rec = lini;
    
    //1. recorro hasta el nodo que contiene el cod
    while(rec){
        if(rec->ped->GetCodigo() == cod){
            //2. actualizo 
            rec->ped->SetOrden(prio); 
            break;
        }
        rec = rec->sig;
    }
}

//TRABAJA CON ELIMINAR NODO 
void Lista::reordenar(){    
    class Nodo *p=lini,*ant=nullptr,*sale;
    while(p){
        if(p->ped->GetOrden()==1){            
            insertarInicio(p->ped);
            sale = p;
            
            if (ant!=nullptr) {
                ant->sig = p->sig;
            } else {
                // Si ant es nulo, estamos en el primer nodo
                lini = p->sig;
            }

            if (p->sig!=nullptr) {
                p->sig->ant = ant; //?????
            } else {
                // Si p->sig es nulo, estamos en el último nodo
                lfin = ant;
            }
            
            p = p->sig;
            delete sale;
        }
        ant=p;
        p=p->sig;
    }
    
}

void Lista::insertarInicio(class Pedido *&dato){
    class Nodo *nuevo = new class Nodo;
    nuevo->ped = dato;
    
    // Insertar al inicio
    nuevo->sig = lini;
    nuevo->ant = nullptr;
    
    if (lini != nullptr) {
        lini->ant = nuevo;
    } else {
        // Si la lista estaba vacía
        lfin = nuevo;
    }
    
    lini = nuevo;
}