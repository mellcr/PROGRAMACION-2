/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "ColaGenerica.h"
#include "ColaConProductos.h"

#define NO_ENCONTRO -1
enum producto {COD,DES,PRE,STOCK};
enum pedido {FECHA,DNI,CANTIDAD};


void procesarPedidos(int **fechaCli,char **codigoPedido,void *productos){
    
}




//----------------------------------------------------------------------------------------------------------
void procesarPedidos(int **fechaCli,char **codigoPedido,void *productos){
    int posPedido;
    void **producto;
    crearColaProductos(productos);
    for(int i=0;fechaCli[i];i++){
        posPedido=buscarPedido(codigoPedido[i],productos);
        producto=(void **)productos;
        if(posPedido!=NO_ENCONTRO){
            agregarPedido(fechaCli[i],producto[posPedido]);
        }
    }
//    
}




void agregarPedido(int *fechaCli,void *prod){
    int cantidadPedida=fechaCli[2];
    void **producto=(void **)prod;
    void **registroProducto=(void **)producto[0],**datos;
    int *stock=(int *)registroProducto[STOCK],stockPrueba,*fecha,
            *cantidad,*dni;
    stockPrueba=(*stock)-cantidadPedida;
//    cout<<stockPrueba<<endl;
    if(stockPrueba>=0){
        fecha=new int;
        cantidad=new int;
        dni=new int;
        datos=new void *[3];
        (*fecha)=fechaCli[FECHA];
        (*cantidad)=fechaCli[CANTIDAD];
        (*dni)=fechaCli[DNI];
        datos[FECHA]=fecha;
        datos[CANTIDAD]=cantidad;
        datos[DNI]=dni;
        encola(producto[1],datos);
        (*stock)-=cantidadPedida;
    }
}
int buscarPedido(char *codigoPedido,void *productos){
    void **aux=(void **)productos;
    for(int i=0;aux[i];i++){
        if(compara(codigoPedido,aux[i]))return i;
    }
    
    return NO_ENCONTRO;
}

bool compara(char *codigoPedido,void *producto){
    void **auxProducto=(void **)producto;
    void **registro=(void **)auxProducto[0];
    char *codigo=(char *)registro[0];
    return (strcmp(codigo,codigoPedido)==0);
}
void crearColaProductos(void *productos){
    void **aux=(void **)productos,**producto,**cola;
    for(int i=0;aux[i];i++){
        producto=(void **)aux[i];
        generacola(producto[1]);
    }
}

void reporteDePedidos(void *productos,const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"Error: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed;
    archRep.precision(2);
    void **auxProductos=(void **)productos ;
    for(int i=0;auxProductos[i];i++){
        archRep<<"Producto  "<<setw(3)<<i+1<<":"<<endl;
        imprimeProductos(auxProductos[i],archRep);
        archRep<<endl<<endl;
    }
}
void imprimeProductos(void *productos,ofstream &archRep){
    void **aux=(void **)productos,*datos;
    void **registro=(void **)aux[0],**cola;
    char *codigo=(char *)registro[COD],*descripcion=(char *)registro[DES];
    double *precio=(double *)registro[PRE];
    int *stockFinal=(int *)registro[STOCK];
    archRep<<setw(7)<<codigo<<setw(10)<<" "<<left<<setw(60)<<descripcion<<right<<endl;
    archRep<<"Precio: "<<setw(8)<<*precio<<setw(10)<<" "<<"Stock: "<<setw(3)<<*stockFinal<<endl;
    archRep<<"Pedidos Aceptados"<<endl;
    archRep<<"Fecha "<<setw(10)<<" "<<"Dni"<<setw(10)<<" "<<"Cantidad"<<endl;
    while(!colavacia(aux[1])){
        datos=desencola(aux[1]);
        imprimePedido(datos,archRep);
    }
}

void imprimePedido(void *datos,ofstream &archRep){
    void **auxDatos=(void **)datos;
    int *fecha=(int *)auxDatos[FECHA],*cantidad=(int *)auxDatos[CANTIDAD],
            *dni=(int *)auxDatos[DNI];
    archRep<<setw(8)<<*fecha<<setw(5)<<" "<<setw(8)<<*dni<<setw(10)<<" "<<setw(2)<<*cantidad<<endl;
}