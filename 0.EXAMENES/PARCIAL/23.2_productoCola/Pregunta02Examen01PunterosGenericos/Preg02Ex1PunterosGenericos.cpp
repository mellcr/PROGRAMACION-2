/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "utils.h"
#include "Preg02Ex1PunterosGenericos.h"
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

//COD DESC PRECIO STOCK
void cargarProductos(void *&productos,const char *filename){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout <<"no";
        exit(1);
    }
    //val aux lect
    char *codProd, *desc,c;
    double prec;
    int stockLeid;
    //val incrementos
    productos = nullptr;
    int numDat=0, capacity = 0;
    while(true){
        codProd = leeCadDelim(arch,',');
        if(codProd==nullptr) break;
        desc = leeCadDelim(arch,',');
        arch>>prec>>c>>stockLeid;
        arch.get(); //salto
        
        if(capacity==numDat)
            incrementarMemIncrem(productos,numDat,capacity);
        
        asignarMemIncre(productos,numDat,codProd,desc,prec,stockLeid);
    }
        
}

//enum Prod{PROD,COLA};
//enum Detalle{COD,DESC,PREC,STOCK};
void asignarMemIncre(void *&productos,int &numDat,char *codProd,char *desc,double prec,int stockLeid){
    double *precio = new double;
    int *stock = new int;
    *precio = prec;
    *stock = stockLeid;
    
    void  **producto = new void *[2]{};
    producto[PROD] = asignaProducto(codProd,desc,precio,stock);
    producto[COLA] = nullptr;
    
    void **productosCast = (void **)productos;      //para acceder a los indices 
    productosCast[numDat-1] = producto;
    numDat++;
    ////
//    void **registro = (void **)producto[PROD];
//        char *cod = (char *)registro[COD];
//    char *descr = (char *)registro[DESC];
//    double *preciOOo = (double *)registro[PREC];
//    int *stooock = (int *)registro[STOCK];
//    cout<<left<<setw(10)<<cod << setw(50)<<descr<<setw(10)
//                <<*preciOOo<<setw(10)<<*stooock<<endl;    
}


void* asignaProducto(char *codProd,char *desc,double *precio,int *stock){
    void **registro = new void *[4]{};
    registro[COD] = codProd;
    registro[DESC] = desc;
    registro[PREC] = precio;
    registro[STOCK] = stock;
    
    return registro;
}
void incrementarMemIncrem(void *&productos,int &numDat,int &capacity){
    void **aux_prod;
    capacity +=INCREMENTOS;
    if(productos==nullptr){
        aux_prod = new void *[capacity]{};
        productos = aux_prod;
        numDat = 1;
    }else{
        void **productosCast = (void **)productos;
        aux_prod = new void *[capacity]{};
        for(int i=0;i<numDat;i++){
            aux_prod[i] = productosCast[i];
        }
        delete productosCast;
        productosCast = aux_prod;
        productos = productosCast;
    }
}

void pruebaCargarProductos(void *productos){
    ofstream arch("PruebaProductos.txt",ios::out);
    if(not arch.is_open()){
        cout <<"no";
        exit(1);
    }
    void **productosCast = (void **)productos;
    
    arch << "CODIGO"<< setw(30)<<"DESC"<< setw(10)<< "PRECIO"<<setw(10)<<"STOCK"<<endl;
    arch << setfill('=')<<setw(100)<< " "<<setfill(' ')<<endl; //imprime linea
    //cout <<"ola"<<endl;
    for(int i=0; productosCast[i]!=nullptr; i++){
        void **producto = (void **)productosCast[i];
        imprimeProducto(producto[PROD],arch);
        //cout <<"ola2"<<endl;
    }    
}

//enum Detalle{COD,DESC,PREC,STOCK};
void imprimeProducto(void *productoDetalle, ofstream &arch){
    void **prodDetCast = (void **)productoDetalle; //para acceder a los campos del producto (detalles)
    char *cod = (char *)prodDetCast[COD];
    char *desc = (char *)prodDetCast[DESC];
    double *precio = (double *)prodDetCast[PREC];
    int *stock = (int *)prodDetCast[STOCK];
    
//    cout <<stock<<endl;
    arch<<left<<setw(10)<<cod << setw(50)<<desc<<setw(10)
                <<*precio<<setw(10)<<*stock<<endl;
}