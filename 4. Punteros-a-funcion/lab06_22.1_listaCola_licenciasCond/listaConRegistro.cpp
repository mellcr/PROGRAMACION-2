/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "listaConRegistro.h"
#include "BibliotecaListaGenerica.h"
using namespace std;
//enum Nodo{DAT,SIG};
//enum Lista{CAB,COLA};
//enum Reg{LIC, PLACA, FECHA,INFRAC};
void* leeregistro(ifstream &arch){
    int *licencia = new int,dia,mes, anho, *infraccion = new int;
    char *placa,c;
    int *fecha = new int;
    
    arch>>*licencia;
    if(arch.eof()) return nullptr;
    arch.get();
    placa = leeCadDelim(arch,',');
    arch>>dia>>c>>mes>>c>>anho>>c>>*infraccion;
    
    *fecha = anho*10000 + mes*100 + dia;
    
    void **registro = new void *[4]{};
    registro[LIC] = licencia;
    registro[PLACA] = placa;
    registro[FECHA] = fecha;
    registro[INFRAC] = infraccion;
    
    return registro;
}

int cmpregistro(const void *a, const void *b){
    //accedemos campos del reg jijijji
    void **camposA = (void **)a;
    void **camposB = (void **)b;
    //COMO EL REGISTRO SOLO GUARDA UN VALOR ENTERO
    int *datoA = (int *)camposA[FECHA];
    int *datoB = (int *)camposB[FECHA];
    
    return *datoA - *datoB;
}

void  imprimeregistro(void *dato, ofstream &arch){
    void **camposA = (void **)dato;
    int *fecha = (int *)camposA[FECHA];
    char *placa = (char *)camposA[PLACA];
    arch<<placa<<"   "<<*fecha<<endl;
}