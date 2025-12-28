/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "AsignacionDinamicaMemoriaExacta.h"



void lecturaDeProductos(const char* nombArch , char *** &productos, int * &stock, double * &precios){
    ifstream archProd(nombArch, ios::in);
    if( not archProd.is_open()){
        cout<<"Hay un error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    //comenzamos a leer    
    char **bufferProd[200]; // char ***  codigo & descricpion
    int buffStock[200];
    double buffPrecios[200];
    int cantProd;
    
    int i=0;
    char buffcadena[100], c;
    while(true){
        archProd.getline(buffcadena, 100, ',');//codigo
        if(archProd.eof()) break;
        
        bufferProd[i] = new char*[2];// char**
        TerminarDeLeerProducto(buffcadena, bufferProd[i] , archProd );
        
        archProd>>buffPrecios[i]>>c>>buffStock[i];
        archProd.get();//eliminar el salto de linea
        
        i++;
    }
    cantProd=i;
    
    productos = new char **[cantProd+1];
    stock = new int[cantProd+1];
    precios = new double[cantProd+1];
    for(int i=0 ; i<cantProd ; i++){
        productos[i] = bufferProd[i];
        stock[i] = buffStock[i];
        precios[i] = buffPrecios[i];
    }
    
}

void TerminarDeLeerProducto(char *buffcadena, char **bufferProd , ifstream &archProd){
    bufferProd[0] = new char[strlen(buffcadena)+1];// char** -> char*
    strcpy(bufferProd[0], buffcadena);

    archProd.getline(buffcadena, 100, ',');//descripcion
    bufferProd[1] = new char[strlen(buffcadena)+1];// char** -> char*
    strcpy(bufferProd[1], buffcadena);  
}


void pruebaDeLecturaDeProductos(const char* nombArch, char ***productos, int *stock,  double *precios){
    
    ofstream archRep(nombArch, ios::out);
    if( not archRep.is_open()){
        cout<<"Hay un error al abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    for(int i=0 ; productos[i] ; i++){ // nullptr -> false
        
        archRep<<"codigo: "<<productos[i][0]<<"   desc:"<<productos[i][1]<< "  stock:"<<stock[i]<<"  precio: "<<precios[i]<<endl;
        
    }
    
    
}