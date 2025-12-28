/* 
 * Proyecto: lab4_23.2
 * Archivo:   PunterosGenericos.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 23 de abril de 2024, 14:06
 */

#include "Utils.h"
#include "PunterosGenericos.h"

//enum Cli{DNI,NOMBRE,LISTA,LINCRED};

void cargaProductos(void *&productos){
    ifstream arch("Productos2.csv",ios::in); 
    if(not arch.is_open()){
        cout <<"no";
        exit(1);
    }
    void *registro, *buff[200]{}; 
    int numDat=0; 
    while(true){
        registro = leeRegProd(arch); 
        if(registro==nullptr) break; 
        
        buff[200] = registro; 
        numDat++;
    }
    
}
char *leeCadDelim(ifstream &arch,char delim){
    char buff[100], *str; 
    
    arch.getline(buff,100,delim); 
    str = new char [strlen(buff)+1];
    strcpy(str,buff); 
    return str; 
}

void *leeRegProd(ifstream &arch){
    char *cod, *desc, *tipo = new char,c;
    double *precio = new double; 
    
    cod = leeCadDelim(arch,','); 
    if(arch.eof()) return nullptr; 
    desc = leeCadDelim(arch,','); 
    arch>>*precio>>c>>*tipo;
    arch.get(); 
    
    void **registro = new void *[4]{}; 
    registro[CODIGO] = cod;
    registro[DESCRIP] = desc;
    registro[PRECIO] = precio;
    registro[TIPO] = tipo;
    
    return registro; 
}