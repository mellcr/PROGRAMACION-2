/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "utils.h"
#include "Preg02_PuntGenerico.h"
#include "Preg01_PuntMult.h"
using namespace std;
enum Producto{COD,DESC,PRECIO,STOCK};
//
void cargarProductos(void *&productos,const char*filename){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout<<"no"<<endl;
        exit(1);
    }
    
    void*registro;
    void *buff[700]{};
    int numDat=0;
    while(true){
        registro = leeRegistroProd(arch);
        if(registro==nullptr) break;
        
        buff[numDat]=registro;
        
        asignaMem();
        numDat++;
    }
    void **exacto = new void *[numDat+1]{}; //ind el fin
    for(int i=0;i<numDat;i++){
        exacto[i] = buff[i];
    }
    productos = exacto;
    
}

void* leeRegistroProd(ifstream &arch){
    void **registro = new void *[4]{};
    
    char *cod,*desc,c;
    double *precio = new double;
    int *stock =  new int;
    
    cod = leeCadDelim(arch,',');
    if(arch.eof()) return nullptr;
    desc = leeCadDelim(arch,',');
    arch>>*precio>>c>>*stock;
    arch.get();
    
    registro[COD] = cod;
    registro[DESC] = desc;
    registro[PRECIO] = precio;
    registro[STOCK] = stock;
    
    return registro;
}
void pruebaDeCargaDeProductos(void *productos){
    
}