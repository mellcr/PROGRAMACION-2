/* 
 * Proyecto: LAB2_CON_INCREMENTOS
 * Archivo:   funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 16 de abril de 2024, 13:23
 */

#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cstring>
#include <random>
using namespace std;
#include "funciones.h"
#define LINEAS 200

//codLib     nomb   autor   stock
void lecturaDeLibros(const char*filename,char***&libros,int **&stock){
    ifstream archPed(filename,ios::in);
    //buff
    char **buff_lib[300]{}; 
    int *buff_stock[300]{}, numDat=0; 
    //val aux
    char codLib[8], nomb[100], autor[70],c; 
    int stockDis; 
    double precio; 
    
    while(true){
        archPed.getline(codLib,8,',');
        if(archPed.eof()) break; 
        archPed.getline(nomb,100,',');
        archPed.getline(autor,70,',');
        archPed>>stockDis>>c>>precio; 
        archPed.get(); //lee el cambio de linea 
        
        llenaLibs(buff_lib[numDat],codLib,nomb,autor); 
        llenaStock(buff_stock[numDat],stockDis); 
        
        numDat++; 
    }
    //4. RESERVA DE MEM A ORIGINALES 
    stock = new int *[numDat+1]{}; 
    libros = new char **[numDat+1]{}; 
    //5. GUARDAR BUFF A ARR_DIN 
    for(int i=0; i<numDat;i++){
        stock[i] = buff_stock[i]; 
       
        libros[i] = buff_lib[i]; 
    }
    
}
void llenaStock(int *&buff_stock,int stockDis){
    buff_stock = new int [2]{}; 
    buff_stock[0] = stockDis; 
    buff_stock[1] = 0;
}

//1. BUFF 
//2. NUM DAT EXACT
//3. LECTURA Y LLENADO DE BUFF
//4. RESERVA DE MEM A ORIGINALES
//5. BUFF A ARR-DIN 
char *asignaCadena(char *cad){
    char *str; 
    int len = strlen(cad); 
    str = new char [len+1]{}; 
    strcpy(str,cad);
    
    return str; 
}
void llenaLibs(char **&buff_lib,char *codLib,char *nomb,char *autor){
    buff_lib = new char*[3]; 
    
    buff_lib[0] = asignaCadena(codLib);
    buff_lib[1] = asignaCadena(nomb); 
    buff_lib[2] = asignaCadena(autor); 
    
}

void pruebaDeLecturaDeLibros(const char*filename,char***libros,int **stock){
    int *aux_stock;
    //QUIERO IMPRIMIR LIBROS 
    for(int i=0; libros[i]; i++){
        imprimeLib(libros[i]);  
        aux_stock = stock[i];
        //cout << aux_stock[0]<<" " <<aux_stock[1]<<endl; 
    }
}
void imprimeLib(char **libros){
    //cout <<left << setw(15)<<libros[0]<<"    "; 
}

int buscarCliente(int cantClientes,int **buffClientes,int dni){
    int *aux_cli;
    for(int i=0; i<cantClientes;i++){
        aux_cli = buffClientes[i];
        if(aux_cli[0]==dni) return i;
    }
    return -1; 
}
void atencionDePedidos(const char *nombPed,char*** libros,int **stock,
        int **pedidosClientes,char ***pedidosLibros,bool **pedidosAtendidos){
    ifstream archPed(nombPed,ios::in);
    int numPed, dni,posCliente; 
    char c,*cod; 
    //buffers
    int *buffClientes[200]{},cantClientes=0,cantPedidos=0, cantSolicitFil[200]{};
    char **buffPedLibros[200]{};
    bool *buffAtendidos[200]{};
    
    while(true){
        archPed>> numPed; 
        if(archPed.eof()) break;
        archPed>>c>>dni; 
        //BUSQUEDA DEL CLIENTE -> NO SE DEBEN REPETIR (ACUMULA SUS LIB PED)
        posCliente = buscarCliente(cantClientes,buffClientes,dni);
        if(posCliente==-1){// ES UN NUEVO CLIENTE
            asignarMemoriaCliente(cantClientes,buffClientes[cantClientes],dni,
                    posCliente);
        }
        //AGREGAR UN PEDIDO ES ALGO GENERAL -> se hace si el cliente existe y cuando es nuevo
        agregarNumPedido(numPed,buffClientes[posCliente]);
        
        
        /**********************PARA PEDIDOS DE LIBROS************/
        //lo hace por niveles:)
        buffPedLibros[numPed-1] = new char*[200]{}; //para cada numPed
        buffAtendidos[numPed-1] = new bool[200]{};  //para cada numPed
        while(true){
            if(archPed.get()=='\n') break;
            cod = LeerCadenaTxt(archPed);//codLib
            asignarMemoriaLibros(buffPedLibros[numPed-1],buffAtendidos[numPed-1],
                    cod,stock,libros,numPed,cantPedidos,cantSolicitFil[numPed-1]);
        }
        cantPedidos;
    }
}

int buscarLibro(char ***libros,char *cod){
    char **aux;
    for(int i=0;libros[i];i++){
        aux = libros[i];
        if(strcmp(aux[0],cod)==0) return i;
    }
    return -1;
}
//es como un LLENARBUFF 
void asignarMemoriaLibros(char **&buffPedLibros,bool *&buffAtendidos,
                    char *cod,int **&stock,char ***libros,int numPed,
                    int &cantPedidos,int &cantSolicitFil){
    int posLibros = buscarLibro(libros,cod);//para el stock
    int *aux_stock;
    
    if(posLibros!=-1){ //existe el cod de ese libro
        aux_stock = stock[posLibros]; //cone sto puedo acceder al stock ini
        
        if(aux_stock[0]>0){//SE PUEDE ATENDER
            buffAtendidos[cantSolicitFil] = true;
            aux_stock[0]--;
        }else{ //NO SE PUEDE ATENDER 
            buffAtendidos[cantSolicitFil] = false;
            aux_stock[1]++;
        }
        
        cantSolicitFil++;
    }
}

char *LeerCadenaTxt(ifstream &archPed){
    char aux[8], *str;
    archPed>>aux;
    
    int len = strlen(aux);
    str = new char[len+1]{};
    strcpy(str,aux);
    
    
    return str;
}
    
void asignarMemoriaCliente(int &cantClientes,int *&buffClientes,int dni,
                    int &posCliente){
    buffClientes = new int[200]{};
    buffClientes[0] = dni;
    buffClientes[1] = 0;
    
    posCliente = cantClientes;
    cantClientes++;
}
void agregarNumPedido(int numPed,int *&buffClientes){
    //hallamos la cantidad de pedidos
    int cantPed = buffClientes[1];
    
    buffClientes[cantPed+2] = numPed;
    buffClientes[0]++; //AUMENTA LA CANT DE PED
}


void imprimeLineas(ofstream &archRep,int lineas, char car){
    for(int i=0;i<lineas;i++)archRep.put(car);
    archRep<<endl;
}

void reporteDeEntregaDePedidos(const char*nombArch,int **pedidosClientes,
            char ***pedidosLibros,bool **pedidosAtendidos){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    archRep<<setw(70)<<" "<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
    imprimeLineas(archRep,LINEAS,'=');
    int *auxClientes;
    for(int i=0;pedidosClientes[i];i++){
        auxClientes=pedidosClientes[i];
        int dni=auxClientes[0];
        archRep<<"CLIENTE: "<<setw(8)<<auxClientes[0]<<endl;
        imprimeLineas(archRep,LINEAS,'=');
        imprimirLibros(pedidosAtendidos,pedidosLibros,pedidosClientes[i],archRep);
                imprimeLineas(archRep,LINEAS,'=');
        
    }
}
void imprimirLibros(bool **pedidosAtendidos,char ***pedidosLibros,
        int *pedidosClientes ,ofstream &archRep){

    int codPed;
    for(int i=2;pedidosClientes[i];i++){
        codPed=pedidosClientes[i]-1;
        archRep<<setw(10)<<" "<<"Pedido No."<<setw(15)<<" "<<"CODIGO DEL LIBRO"<<
        setw(21)<<" "<<"OBSERVACION"<<endl;
      
        archRep<<setw(12)<<" "<<setfill('0')<<setw(6)<<codPed+1<<setfill(' ')<<setw(22)<<
                " ";
        if(pedidosLibros[codPed]!=nullptr){
            imprimeAtendido(pedidosAtendidos[codPed],pedidosLibros[codPed],archRep);
            archRep<<endl;
            imprimeLineas(archRep,LINEAS,'-'); 
        }

    }
}

void imprimeAtendido(bool *pedidosAtendidos,char **pedidosLibros,ofstream &arcRep){
    int k;
   
    for(int i=0;pedidosLibros[i];i++){
        k=i;
        arcRep<<setw(7)<<pedidosLibros[i]<<setw(15)<<" ";
        if(pedidosAtendidos[i]==true){
            arcRep<<setw(20)<<"ATENDIDO"<<endl;
        }
        else{
            arcRep<<setw(20)<<"NO ATENDIDO"<<endl;
        }
        arcRep<<setw(40)<<" ";
    }    
    
}