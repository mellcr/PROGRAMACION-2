/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
using namespace std;
//enum Nodo{DAT,SIG};
//enum Lista{CAB,COLA};


//enum Reg{LIC, PLACA, FECHA,INFRAC};
void* leenum(ifstream &arch){
    int licencia,dia,mes, anho,infraccion;
    char *placa,c;
    int fecha;
    
    arch>>licencia;
    if(arch.eof()) return nullptr;
    arch.get();
    placa = leeCadDelim(arch,',');
    arch>>dia>>c>>mes>>c>>anho>>c>>infraccion;
    
    fecha = anho*10000 + mes*100 + dia;
    int *reg = new int;
    *reg = fecha;
    return reg;
}
    
int cmpnum(const void *a, const void *b){
    //COMO EL REGISTRO SOLO GUARDA UN VALOR ENTERO
    int *datoA = (int *)a;
    int *datoB = (int *)b;
    
    return *datoA - *datoB;
}

void  imprimenum(void *dato, ofstream &arch){
    int *fecha = (int *)dato;
    arch<<*fecha<<endl;
}