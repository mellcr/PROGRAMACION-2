/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"
#define INCREMENTO 5
void cargarPedidos(int **&fecha,char **&codigo,const char *nombArch){
    ifstream archPedidos(nombArch,ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR EN EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    int cantDatos=0,capacidad=0,fechaCompleta,dni,cantidad;
    char *codProducto,car;
    codigo=nullptr;
    fecha=nullptr;
    while(true){
        codProducto=leerCadena(archPedidos);
        if(archPedidos.eof())break;
        archPedidos>>dni>>car>>cantidad>>car;
        leerFecha(fechaCompleta,archPedidos);
        if(cantDatos==capacidad){
            aumentarEspacios(fecha,codigo,cantDatos,capacidad);
        }
        asignarDatos(codigo[cantDatos-1],fecha[cantDatos-1],codProducto,fechaCompleta,dni,cantidad);
        cantDatos++;
    }
    quicksort(fecha,codigo,0,cantDatos-2);
}
void quicksort(int **&fecha,char **&codigo,int izq,int der){
    int limite,pos;
    if(izq>=der)return;
    pos=(izq+der)/2;
    cambiar(fecha[izq],fecha[pos],codigo[izq],codigo[pos]);
    limite=izq;
    for(int i=izq+1;i<=der;i++){
        if(comparar(fecha[i],fecha[izq])<0){
            limite++;
            cambiar(fecha[limite],fecha[i],codigo[limite],codigo[i]);
        }
    }
    cambiar(fecha[limite],fecha[izq],codigo[limite],codigo[izq]);
    quicksort(fecha,codigo,izq,limite-1);
    quicksort(fecha,codigo,limite+1,der);
            
}

int comparar(int *fechaI,int *fechaK){
    return fechaI[0]-fechaK[0];
}
void cambiar(int *&fechaIzq,int *&fechaPos,char *&codigoIzq,char *&codigoPos){
    int *auxInt;
    auxInt=fechaIzq;
    fechaIzq=fechaPos;
    fechaPos=auxInt;
    
    char *auxCod;
    auxCod=codigoIzq;
    codigoIzq=codigoPos;
    codigoPos=auxCod;
}
void asignarDatos(char *&codigo,int *&fecha,char *codProducto,int fechaCompleta,
        int dni,int cantidad){
    codigo=codProducto;
    fecha=new int[3];
    fecha[0]=fechaCompleta;
    fecha[1]=dni;
    fecha[2]=cantidad;
}

void aumentarEspacios(int **&fecha,char **&codigo,int &cantDatos,int &capacidad){
    capacidad+=INCREMENTO;
    if(fecha==nullptr){
        fecha=new int *[capacidad]{};
        codigo=new char *[capacidad]{};
        cantDatos=1;
    }
    else{
        int **auxFecha=new int *[capacidad]{};
        char **auxCod=new char *[capacidad]{};
        for(int i=0;i<cantDatos;i++){
            auxCod[i]=codigo[i];
            auxFecha[i]=fecha[i];
        }
        delete fecha;
        delete codigo;
        fecha=auxFecha;
        codigo=auxCod;
    }
}
void leerFecha(int &fecha,ifstream &archPedidos){
    int dd,mm,aaaa;
    char car;
    archPedidos>>dd>>car>>mm>>car>>aaaa>>ws;
    fecha=dd+mm*100+aaaa*10000;
     
}
char * leerCadena(ifstream &arch){
    char cadena[60],*nuevaCadena;
    arch.getline(cadena,60,',');
    if(arch.eof())return nullptr;
    nuevaCadena=new char[strlen(cadena)+1];
    strcpy(nuevaCadena,cadena);
    return nuevaCadena;
}

void pruebaCargaDePedidos(int **fechaClienteCantidad,char **codigoDelProducto,
        const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR EN EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    archRep<<setw(30)<<" "<<"REPORTE DE PEDIDOS"<<endl;
    imprimeLinea(archRep,'=');
    archRep<<setw(5)<<" "<<"CODIGO"<<setw(7)<<" "<<"FECHA DEL PEDIDO"<<
            setw(10)<<" "<<"DNI"<<setw(7)<<" "<<"CANTIDAD"<<endl;
    imprimeLinea(archRep,'-');
    int *auxFecha;
    char *auxCod;
    int dd,mm,aaaa;
    for(int i=0;fechaClienteCantidad[i];i++){
        auxFecha=fechaClienteCantidad[i];
        auxCod=codigoDelProducto[i];
        aaaa=auxFecha[0]/10000;
        mm=(auxFecha[0]%10000)/100;
        dd=(auxFecha[0]%10000)%100;
        archRep<<setw(5)<<" "<<setw(7)<<auxCod<<setw(10)<<" "<<
                setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<
                setw(4)<<aaaa<<setfill(' ')<<setw(10)<<" "<<setw(8)<<auxFecha[1]<<
                setw(7)<<" "<<setw(2)<<auxFecha[2]<<endl;
    }
}

void imprimeLinea(ofstream &arch,char car){
    for(int i=0;i<200;i++)arch.put(car);
    arch<<endl;
}