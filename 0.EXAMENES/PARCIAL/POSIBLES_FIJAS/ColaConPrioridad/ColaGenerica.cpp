/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iostream>
#include <valarray>
#include "ColaGenerica.h"
using namespace std;
enum Cola{CABEZA,COLA,PRI1,PRI2}; 
enum Nodo{DATO, SIG};
enum Registro{NOMB,EDAD,SUELDO};

void *desencola(void *&cola){
    void **castCola = (void **)cola; 
    void *dato;
    
    void **primerNodo = (void **)castCola[CABEZA]; 
    
    if(primerNodo[SIG]==nullptr){
        castCola[COLA] = nullptr; 
    }
    dato = primerNodo[DATO]; 
    castCola[CABEZA] = primerNodo[SIG]; 
    delete primerNodo; 
    return dato; 
}



//if(edad>=80) -> prioridad 1
void encola(void *&cola, void *dato){
    void **castCola = (void **)cola;
    
    //1, crear nodo
    void **nuevoNodo = new void*[2]{};
    nuevoNodo[DATO] = dato; 
    nuevoNodo[SIG] = nullptr; 
    
    if(colavacia(cola)){
        castCola[CABEZA] = nuevoNodo; 
        castCola[COLA]= nuevoNodo; 
    }else{
        void **ultNodo = (void **)castCola[COLA];
        ultNodo[SIG] = nuevoNodo; 
        castCola[COLA] = nuevoNodo; 
    }
}
void inicializaCola(void *&cola){
    void **castCola = new void*[4]{}; 
    
    castCola[CABEZA] = nullptr;
    castCola[COLA] = nullptr;
    castCola[PRI1] = nullptr;
    castCola[PRI2] = nullptr;
    
    cola = castCola;
}


void encolaPrioridad(void *&cola, void *dato){
    void **castCola = (void **)cola;
    //1, crear nodo
    void **nuevoNodo = new void*[2]{};
    nuevoNodo[DATO] = dato; 
    nuevoNodo[SIG] = nullptr;
    
    void **castDato = (void **)dato; 
    int *edad = (int *)castDato[EDAD]; 
    
    if(colavacia(cola)){
        castCola[CABEZA] = nuevoNodo; 
        castCola[COLA]= nuevoNodo; 
        if(*edad >=80){ //prioridad 1 
            castCola[PRI1] = nuevoNodo;
        }else castCola[PRI2] = nuevoNodo;
    }else{
        
        if(*edad >= 80){ //prioridad 1 
            if(castCola[PRI1]==nullptr){ //si es full pri2
                nuevoNodo[SIG] = castCola[CABEZA]; 
                castCola[CABEZA] = nuevoNodo; 
                castCola[PRI1] = nuevoNodo; //ahora el pri1 apunta al nuevoNdo 
            }else{ //tiene prioridad1
                //no se sabe si tiene prioridad 2
                //simplemente encolamos al final de prio1 
                void **colaPri1 = (void **)castCola[PRI1];
                nuevoNodo[SIG] = colaPri1[SIG]; //apunta al inicio de pri1 o al null si no tiene pri2
                colaPri1[SIG] = nuevoNodo; 
                //asigno la nueva direc de prio1
                castCola[PRI1] = nuevoNodo; 
            }
        }else{ //ES PRIORIDAD 2 
            if(castCola[PRI2] ==nullptr){  //NO TENEMOS PRI2
                //¿existe on o existe pri1?
                if(castCola[PRI1]==nullptr){ //no hay pri1
                    nuevoNodo[SIG] = castCola[CABEZA]; 
                    castCola[CABEZA] = nuevoNodo; 
                    castCola[PRI2] = nuevoNodo; 
                }else{ //si hay pri1
                     void **ultPri1 = (void **)castCola[PRI1];
                     nuevoNodo[SIG] = ultPri1[SIG]; 
                     castCola[PRI1] = nuevoNodo; 
                }
            }else{ //si existe prioridad 2 , como es la ult prioridad , encolamos al final 
                //la prioridad es la cola :O
                void **ultPri2 = (void **)castCola[PRI2]; //castCola[COLA]
                 ultPri2[SIG] = nuevoNodo; 
                 castCola[COLA] = nuevoNodo; 
                 castCola[PRI2] = nuevoNodo; 
                 nuevoNodo[SIG] = nullptr; 
            }
        }
    }
}

bool colavacia(void *cola){
    void **castCola = (void **)cola; 
    
    if(castCola[CABEZA]==nullptr and castCola[COLA]==nullptr) return true; 
    else return false; 
}