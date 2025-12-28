/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "utils.h"
#include "Preg01Ex1PunterosMultiples.h"
#define INCREMENTOS 5
using namespace std;

char *leeCadDelim(ifstream &arch, char delim){
    char *str, buff[100];
    arch.getline(buff,100,delim);
    if(arch.eof()) return nullptr;
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    
    return str;
}

// METODO MEMORIA POR INCREMENTOS
void cargarPedidos(int **&fechaClienteCant,char **&codigoDelProducto,const char *filename ){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout <<"no";
        exit(1);
    }
    //AUX LECT
    char *codProd,c;
    int dni,cant,dia,mes,anho,fecha;
    //AUX MET POR INCR
    fechaClienteCant = nullptr;
    codigoDelProducto = nullptr;
    int capacity =0, numDat = 0;
    while(true){
        codProd = leeCadDelim(arch,',');
        if( codProd==nullptr) break;
        arch >>dni>>c>>cant>>c>>dia>>c>>mes>>c>>anho;
        arch.get();//saltp
        fecha = anho*10000 + mes *100 + dia;
       //cout <<fecha<<endl;
        if(capacity==numDat)
            incrementarMemIncrem(fechaClienteCant,codigoDelProducto, capacity, numDat);
        
        asignarEnMemIncrem(fechaClienteCant[numDat-1],codigoDelProducto[numDat-1], numDat, 
                codProd,dni,cant,fecha);
    }
    
    //ORDENAMOS LOS DATOS POR FECHA (ASC) 
    sort_Pedidos(fechaClienteCant,codigoDelProducto);
}

void asignarEnMemIncrem(int *&fechaClienteCant,char *&codigoDelProducto, int &numDat, 
                char *codProd,int dni,int cant,int fecha){
    fechaClienteCant = new int [3]{};
    fechaClienteCant[0] = fecha;
    fechaClienteCant[1] = dni;
    fechaClienteCant[2] = cant;
    
    codigoDelProducto = codProd;
//    cout <<fechaClienteCant[0]<<" "<<fechaClienteCant[1]<< " "<< fechaClienteCant[3]<<"  "<<cant<<endl;
    
    numDat++;
}

void incrementarMemIncrem(int **&fechaClienteCant,char **&codigoDelProducto, int & capacity, int &numDat){
    //aux
    int **aux_fecha;
    char **aux_cod;
    
    capacity +=INCREMENTOS;
    if(fechaClienteCant ==nullptr){ //es la priumera vez
        fechaClienteCant = new int *[capacity]{};
        codigoDelProducto = new char *[capacity]{};
        numDat = 1;
    }else{// EXISTENM DATOS 
        aux_fecha = new int *[capacity]{};
        aux_cod = new char *[capacity]{};
        for(int i=0; i<numDat; i++){
            aux_fecha[i] = fechaClienteCant[i];
            aux_cod[i] = codigoDelProducto[i];
        }
        delete fechaClienteCant;
        delete codigoDelProducto;
        fechaClienteCant = aux_fecha;
        codigoDelProducto = aux_cod;
    }
}

void pruebaDeCargaDePedidos(int **fechaClienteCant,char **codigoDelProducto,const char *filename){
    ofstream arch(filename,ios::out);
    if(not arch.is_open()){
        cout <<"no";
        exit(1);
    }
    
    arch << "FECHA"<< setw(10)<<"DNI"<< setw(10)<< "CANT"<<setw(20)<<"CODIGO"<<endl;
    arch << setfill('=')<<setw(100)<< " "<<setfill(' ')<<endl; //imprime linea
    
    for(int i=0; codigoDelProducto[i]!=nullptr; i++){
        int *aux_fechaCliCant = fechaClienteCant[i];
        char *aux_cod = codigoDelProducto[i];
        
        arch<<left<<setw(10)<<aux_fechaCliCant[0] << setw(10)<<aux_fechaCliCant[1]<<setw(10)
                <<aux_fechaCliCant[2]<<setw(10)<<aux_cod<<endl;
//        arch<<aux_fechaCliCant[0]<<" "<<aux_fechaCliCant[1]<<" "<<aux_fechaCliCant[2]<<" "<<aux_cod<<endl;
    }

}\

void sort_Pedidos(int **&fechaClienteCant,char **&codigoDelProducto){
    //conseguimos numDat
    int n=0;
    while(codigoDelProducto[n]) n++;
    quick_sort(fechaClienteCant,codigoDelProducto,0,n-1); //izq   der
}

void quick_sort(int **&fechaClienteCant,char **&codigoDelProducto,int izq,int der){
    int limit, pivot;
    if(izq >= der) return;
    pivot = (izq+der)/2;
    
    swap2(fechaClienteCant[izq],fechaClienteCant[pivot],codigoDelProducto[izq],codigoDelProducto[pivot]);
    limit = izq;
    for(int i=izq+1; i<=der;i++){
        int *aux_fecha = fechaClienteCant[i];
        int *aux_IzqFech = fechaClienteCant[izq];
        if(aux_fecha[0] < aux_IzqFech[0]){
            limit++;
            swap2(fechaClienteCant[limit],fechaClienteCant[i],codigoDelProducto[limit],codigoDelProducto[i]);
        }
    }
    swap2(fechaClienteCant[limit],fechaClienteCant[izq],codigoDelProducto[limit],codigoDelProducto[izq]);
    quick_sort(fechaClienteCant,codigoDelProducto,izq,limit-1);
    quick_sort(fechaClienteCant,codigoDelProducto,limit+1,der);
}

void swap2(int *&fechaI,int *&fechaJ,char *&codigoI,char *&codigoJ){
    char *aux_cod;
    int *aux_date;
    
    aux_cod = codigoI;
    codigoI = codigoJ;
    codigoJ = aux_cod;
    
    aux_date = fechaI;
    fechaI = fechaJ;
    fechaJ = aux_date;
}