
/* 
 * File:   Programa.cpp
 * Author: mell1
 * 
 * Created on 19 de junio de 2024, 19:55
 */
#include "Utils.h"
#include "Programa.h"
#include "NProductos.h" 
#include <iterator>
using namespace std;

Programa::Programa() {
}

Programa::Programa(const Programa& orig) {
}

Programa::~Programa() {
}


//1,0,10,412041,TORTILLAS DE MAIZ 1KG,15
// GUARDAMOS EN EL VECTOR -> aca nomas 
//vector<class NProductos>vproductos;
void Programa::cargaproductos(){
    ifstream arch("productos4.csv",ios::in);
    if(!arch.is_open()){
        cout <<"no se abre ppip"<<endl;
        exit(1);
    }
    class NProductos nAux;
    while(true){
        nAux.leeproductos(arch);
        if(arch.eof()) break;
        vproductos.push_back(nAux);
    }
}
    
void Programa::muestraproductos(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch.is_open()){
        cout <<"no se abre ppip"<<endl;
        exit(1);
    }
    
    arch<<"STL-vector: Productos"<<endl;
    arch<<"prio"<<endl;
    for(int i=0; i<vproductos.size();i++){
        vproductos[i].imprimeproductos(arch);
    }
    
    lpedidos.imprimeDatos(arch);
}


void Programa::carga(){
    cargaproductos();
    cargaLista();
}

//118050,8,8,79475585,16/12/2021
void Programa::cargaLista(){
    ifstream arch("pedidos4.csv",ios::in);
    if(!arch.is_open()){
        cout <<"no se abre ppip"<<endl;
        exit(1);
    }
    lpedidos.leerPedidos(arch);
}

void Programa::actualiza(){
    int prio, codProd; 
    
    //recorre el vector para actualizar -> se comporta como puntero 
    for(vector<class NProductos>::iterator it=vproductos.begin(); 
            it!=vproductos.end(); it++){
        (*it).getPriYCodProd(prio,codProd); 
        //actualiza el atributo orden del pedido con la info de vector 
        lpedidos.actualizaOrden(prio,codProd); 
    }
    //re-ordena la lista de acuerdo a la prioridad :) 
    lpedidos.reordenar(); 
}