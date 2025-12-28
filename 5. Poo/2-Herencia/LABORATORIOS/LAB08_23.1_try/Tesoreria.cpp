
/* 
 * File:   Tesoreria.cpp
 * Author: mell1
 * 
 * Created on 28 de mayo de 2024, 15:24
 */
#include "Utils.h"
#include "Tesoreria.h"
using namespace std; 

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas(const char*filename){
    ifstream arch(filename,ios::in); 
    if(not arch.is_open()){
        cout <<" no se abrio "<<endl; 
        exit(1); 
    }
    
    int cod; 
    double costoCred; 
    //insertamos de acuerdo al codigo
    while(true){
        arch>>cod; 
        if(arch.eof()) break; 
        arch.get(); 
        arch>>costoCred; 
        
        lescala[cod-1].SetCodigo(cod); 
        lescala[cod-1].SetPrecio(costoCred); 
    }
}

//S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,30
void Tesoreria::cargaalumnos(const char*filename){
    ifstream arch(filename,ios::in); 
    if(not arch.is_open()){
        cout <<" no se abrio "<<endl; 
        exit(1); 
    }
    char tipo,c; 
    int cantV=0, cantP=0, cantS=0; 
    
    while(true){
        //cout<<"ola";
        arch>>tipo; 
        //cout<<tipo<<endl;
        if(arch.eof()) break; 
        arch.get(); 
        if(tipo=='P'){
            lpresencial[cantP].leerDatos(arch); 
            cantP++;
        }
        else if(tipo=='S'){
            lsemipresencial[cantS].leerDatos(arch); 
             cantS++;
        }
        else if(tipo=='V'){
                 lvirtual[cantV].leerDatos(arch); 
                cantV++;         
        }
        //else while(arch.get()!='\n');
        
    }
    lpresencial[cantP].SetCodigo(0);
    lsemipresencial[cantP].SetCodigo(0);
    lvirtual[cantP].SetCodigo(0);
}
//dependiendo del tipo: desc/ recarg /licencia


void Tesoreria::actualiza(int cantCred){
    int escala; 
    double precioEsc; 
    //cout <<lpresencial[0].GetCodigo();
    for(int i=0; lpresencial[i].GetCodigo(); i++){
        escala = lpresencial[i].GetEscala();
        precioEsc = lescala[escala-1].GetPrecio(); 
        lpresencial[i].actualiza(cantCred*precioEsc); 
    }
    
    for(int i=0; lsemipresencial[i].GetCodigo(); i++){
        escala = lsemipresencial[i].GetEscala();   //obtenemos la escala 
        precioEsc = lescala[escala-1].GetPrecio();  //precio por escala
        lsemipresencial[i].actualiza(cantCred*precioEsc); 
    }
    
    for(int i=0; lvirtual[i].GetCodigo(); i++){
        escala = lvirtual[i].GetEscala();   //obtenemos la escala 
        precioEsc = lescala[escala-1].GetPrecio();  //precio por escala
        lvirtual[i].actualiza(cantCred*precioEsc); 
    }
}
    
void Tesoreria::imprime(const char*filename){
    ofstream arch(filename,ios::out); 
    if(not arch.is_open()){
        cout <<" no se abrio "<<endl; 
        exit(1); 
    }
    
    arch.precision(2); 
    arch<<fixed; 
    arch<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre"<<right <<setw(3)<<"Escala"
            <<right<<setw(12)<<"Licencia"<<setw(8)<<"Total"<<endl; 
    imprimeLinea(arch); 
    //if(lpresencial[0].GetCodigo()==0) arch<<"no"<<endl;
    for(int i=0; lpresencial[i].GetCodigo(); i++){
        lpresencial[i].imprime(arch); 
    }
    for(int i=0; lsemipresencial[i].GetCodigo(); i++){
        lsemipresencial[i].imprime(arch); 
    }
    for(int i=0; lvirtual[i].GetCodigo(); i++){
        lvirtual[i].imprime(arch); 
    }
}

void Tesoreria::imprimeLinea(ofstream &arch){
    for(int i=0; i<100; i++) arch<<'='; 
    arch<<endl; 
}