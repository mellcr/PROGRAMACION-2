
/* 
 * File:   Tienda.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 10:46
 */
#include "Utils.h"
#include "Tienda.h"
using namespace std; 

Tienda::Tienda() {
}

Tienda::Tienda(const Tienda& orig) {
}

Tienda::~Tienda() {
}

//785062,4,33713901,05/08/2020
void Tienda::carga(){
    ifstream archPed("pedidos3.txt",ios::in); 
    if(not archPed.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1); 
    }
    ifstream archCli("clientes2.txt",ios::in); 
    if(not archCli.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1); 
    }
    
    int nPed=0,nCli=0; 
    while(true){
        lpedidos[nPed].leer(archPed); 
        if(archPed.eof()) break; 
        nPed++; 
        
    } 
    lpedidos[nPed].SetCodigo(0); 
    
    while(true){
//         cout <<nCli<<" ";
        lclientes[nCli].leer(archCli); 
        if(archCli.eof()) break; 
        nCli++; 
        
    }
    lclientes[nCli].SetDni(0); 
}

void Tienda::muestra(){
    ofstream arch("ReporteFinal.txt",ios::out); 
    if(not arch.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1); 
    }
    arch<<left<<setw(15)<<"Fecha"<<setw(15)<<"Codigo"<<
            setw(60)<<"Descripcion"<<right<<setw(4)<<
            "Cantidad"<<setw(10)<<"Precio"<<setw(10)<<
            "Total"<<left<<"  "<<setw(50)<<"Observaciones"<<endl; 
    for(int i=0; lpedidos[i].GetCodigo();i++){
        //cout <<"Hola  "; 
        lpedidos[i].muestra(arch); 
    }
}

void Tienda::actualiza(int stockBase){
    int posCli,codProdPed,stockProd; 
    //recorremos el arreglo de pedidos 
    for(int i=0; lpedidos[i].GetCodigo(); i++){
        codProdPed = lpedidos[i].GetCodigo(); 
        stockProd = lpedidos[i].GetStock();
        //cout <<codProdPed/100000<<endl; 
        if(codProdPed/100000 ==4 and stockProd>=stockBase){
            //cout <<lpedidos[i].GetDni()<<endl;
            posCli = buscarEnCliente(lpedidos[i].GetDni());
            //cout <<posCli<<endl ; 
            if(posCli!=-1){
                lpedidos[i].agregaDescuento(lclientes[posCli].GetCategoria()); 
            }
        }
    }
}

int Tienda::buscarEnCliente(int dniBus){
    for(int i=0; lclientes[i].GetDni(); i++){
        //cout <<lclientes[i].GetDni()<<endl; 
        if(dniBus == lclientes[i].GetDni()) return i; 
    }
    return -1; 
}