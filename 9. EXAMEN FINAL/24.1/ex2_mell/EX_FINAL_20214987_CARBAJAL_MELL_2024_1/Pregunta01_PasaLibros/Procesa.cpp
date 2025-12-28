/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: alulab14
 * 
 * Created on 9 de julio de 2024, 09:40 AM
 */
#include "Utils.h"
using namespace std; 
#include "Procesa.h"
#include "Novela.h"
#include "Revista.h"
#include "Ejemplar.h"


Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

//
void Procesa::carga(){
    ifstream arch("Libros5.csv",ios::in); 
    if(!arch.is_open()){
        cout<<"pipi"<<endl; 
        exit(1); 
    }
    
    class Ejemplar *dato; 
    char tipo; 
    
    while(true){
        arch>>tipo; 
        if(arch.eof()) break; 
        arch.get(); 
        //reserva memoria para dato de acuerdo a su tipo 
        dato = new class Ejemplar; 
        asignarMemoria(tipo,dato); 
        //lectura de dato 
        dato->leeEjemplares(arch); 
        //apilamos 
        porigen.apilar(dato); 
    }
    //cout<<porigen.getNelementos();
}

void Procesa::asignarMemoria(char tipo,class Ejemplar *&dato){
    dato->asignaMem(tipo); 
}

//MOVER LOS ELEMENTOS DE LA PORIGEN A LA PDESTINO 
void Procesa::pasa(){
    //valor 
    while(!porigen.pilaVacia()){
        //valor = porigen.desapilar();
    }
}
//
//char *nombre;
//    int paginas;
//    double peso; 
//    //NOVE
//    char *autor; 
//    char *editorial; 
//    //REV
//     int ISSN; 
//    int anho; 
//    int numero; 
void Procesa::muestra(){
    ofstream arch("Reporte.txt",ios::out); 
    if(!arch.is_open()){
        cout<<"pipi"<<endl; 
        exit(1); 
    }
    
    //en cada ejemplar usar met polimorf imprime -> la pila no se recorre 
    porigen.desapilar();
}