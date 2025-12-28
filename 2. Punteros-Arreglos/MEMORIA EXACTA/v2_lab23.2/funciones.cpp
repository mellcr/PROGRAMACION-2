/* 
 * Proyecto: v2_lab23.2
 * Archivo:   funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 12 de abril de 2024, 0:28
 */

#include "Utils.h"
#include "funciones.h"
using namespace std;


void lecturaDeProductos(const char*filename,char***&productos,int *&stock,
        double *&precios){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }
    
    char** bufferProd[200]{}, cod[8],desc[70],c;
    int bufferStock[200]{},numDat=0;
    double bufferPrecios[200]{};
    
    while(true){
        arch.getline(cod,8,',');   
        if(arch.eof()) break;
        arch.getline(desc,70,',');
        arch>>bufferPrecios[numDat]>>c>>bufferStock[numDat];
        arch.get();
        bufferProd[numDat]=llenaBuffCodDesc(cod,desc); //char**
        //cout <<bufferPrecios[numDat]<<endl;
        numDat++;
        
    }
    actualizaProductos(bufferPrecios,bufferProd,bufferStock,productos,stock,
            precios,numDat);
}
//4. RESERVA MEM ORIGINAL
//5. BUFF A ARR_DIN
void actualizaProductos(double *bufferPrecios,char ***bufferProd,int *bufferStock,
        char ***&productos,int *&stock,double *&precios,int numDat){
    //4
    productos = new char**[numDat+1]{};
    stock = new int[numDat+1]{};
    precios = new double[numDat+1]{};
    
    //5
    for(int i=0;productos[i];i++){
        productos[i] = bufferProd[i];
        stock[i] = bufferStock[i];
        precios[i] = bufferPrecios[i];
        cout<<productos[i][1]<<" "<< stock[i]<<" "<<precios[i]<<endl;
    }
    
}

char * asignaCadena(char *cad){
    char *str;
    str = new char[strlen(cad)+1];
    strcpy(str,cad);
    
    return str;
}

char ** llenaBuffCodDesc(char *cod,char *desc){
    char **aux_bufferProd;
    aux_bufferProd = new char *[2]{};
    aux_bufferProd[0] = asignaCadena(cod);
    aux_bufferProd[1] = asignaCadena(desc);
    return aux_bufferProd;
}

void pruebaDeLecturaDeProductos(const char*filename,char***productos,int *stock,
        double *precios){
    ofstream arch(filename,ios::out);
    if(not arch.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }    
    char ** aux_prod;
    
    arch<<"REPORTE DE PRODUCTOS:"<<endl;
    for(int i=0;productos[i];i++){
        aux_prod =productos[i]; //char **
        cout << aux_prod[0]<< "    "<<aux_prod[1]<<"     ";
        cout<<stock[i]<<"   "<<precios[i]<<endl;
    }
    
}

//1. BUFF
//2. NUM EXACTO 
//3. LLENADO 
//4. MEMORIA EXACTAS ORIGINALES
//5. BUFF A ARR_DIN