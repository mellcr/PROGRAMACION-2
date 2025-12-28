/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include  "Utils.h"
#include "colaGenerica.h"
#define MAXBLANC 20
using namespace std;

int sacaEdad(void *dato){
    void **castDato = (void **)dato;
    int *edad = (int *)castDato[EDAD];
    return *edad;
}

//enum Cola{CAB,COLA,REC,CANT};
//enum Nodo{DATO,SIG,ANT};
//enum Registro{NOMB,EDAD,SUELDO};
void encolaPrioridad_v2(void *&cola,void *dato){
    void **castCola = (void **)cola;
    int edadDato = sacaEdad(dato);
    //CREACION DE NODO A INSERTAR
    void **nuevoNodo = new void*[3]{};
    nuevoNodo[DATO] = dato;
    nuevoNodo[SIG] = nullptr;
    nuevoNodo[ANT] = nullptr;
     
    if(colavacia(cola)){
        castCola[CAB] = nuevoNodo; 
        castCola[COLA] = nuevoNodo;
    }
    else{
        //INSERTAR AL INICIO -> P1
         if(edadDato>=80){
            void **nodoCab = (void **)castCola[CAB];
            nodoCab[ANT] =nuevoNodo;
            nuevoNodo[SIG] = nodoCab;
            castCola[CAB] = nuevoNodo;
        }
        //INSERTAR CON P2 -> REC
        else if(edadDato<10){ 
            //1. recorremos hasta encontrar ult nodo de la pri1
            void **rec = (void **)castCola[CAB];
            while(rec!=nullptr and sacaEdad(rec[DATO])>=80){ //mientras sea prioridad1
                rec = (void **)rec[SIG]; // REC cae justo en el primer nodo q no es pri1
            }
            //CASO 1: FULL PRI3 -> no cumple pri1
            if(rec==(void**)castCola[CAB]){
                void **nodoCab = (void **)castCola[CAB];
                nodoCab[ANT] = nuevoNodo;
                nuevoNodo[SIG] = nodoCab;
                castCola[CAB] = nuevoNodo;
            }
            //CASO 2:  FULL PRI1
            else if(rec==nullptr){
                void **nodoCola = (void **)castCola[COLA];
                nodoCola[SIG] = nuevoNodo;
                nuevoNodo[ANT] = nodoCola;
                castCola[COLA] = nuevoNodo;
            }
            //CASO 3: pri1 + (pri2 o pri3)
            else{
                void **nodoAnt = (void **)rec[ANT];
                nodoAnt[SIG] = nuevoNodo;
                nuevoNodo[ANT] = nodoAnt;

                nuevoNodo[SIG] = rec;
                rec[ANT] = nuevoNodo;
            }
         }
        //INSERTAR AL FIN -> P3
        else{
            void **nodoUlt = (void **)castCola[COLA];
            nodoUlt[SIG] = nuevoNodo;
            nuevoNodo[ANT] = nodoUlt;
            castCola[COLA] = nuevoNodo;
        }
    }
}


void inicializaCola(void *&cola){
    void **castCola = new void*[3]{}; 
    int *cant = new int;
    *cant = 0;
    
    castCola[CAB] = nullptr;
    castCola[COLA] = nullptr;
    castCola[REC] = nullptr;
    castCola[CANT] = cant;
    
    cola = castCola;
}

bool colavacia(void *cola){
    void **castCola = (void **)cola; 
    
    if(castCola[CAB]==nullptr and castCola[COLA]==nullptr) return true; 
    else return false; 
}

void *desencola(void *&cola){
    void **castCola = (void **)cola; 
    void *dato;
    
    void **primerNodo = (void **)castCola[CAB]; 
    
    if(primerNodo[SIG]==nullptr){
        castCola[COLA] = nullptr; 
    }
    dato = primerNodo[DATO]; 
    castCola[CAB] = primerNodo[SIG]; 
    delete primerNodo; 
    return dato; 
}

//enum Registro{NOMB,EDAD,SUELDO};
void imprimeCola(void *cola,const char *filename){
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
        
        arch<<left<<setw(10)<<nomb<<right<<setw(10)<<*edad<<setw(10)<<*sueldo<<endl;
        
    }
}
