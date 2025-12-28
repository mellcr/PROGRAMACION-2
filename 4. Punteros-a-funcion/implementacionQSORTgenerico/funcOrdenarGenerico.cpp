/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "Utils.h"
using namespace std;
#include "funcionesCmp.h"
enum Reg{DNI,NOMBRE,SUELDO};


int voidCmpSueldo(const void *a, const void*b){
    void **ai = (void **)a, **bi = (void **)b;
    //es similar a -> "acceder a campos" -> ai ahora es void *
    void **regA= (void**)(ai[0]);
    void **regB = (void **)(*bi);
    
    double *sueldoA = (double *)(regA[SUELDO]),*sueldoB= (double *)(regB[SUELDO]);
    return *sueldoA- *sueldoB; //ORDENA DE MENOR A MAYOR
   // return *sueldoB- *sueldoA; //ORDENA DE MAYOR A MENOR
}

int miIntCmp(const void *dI, const void *dK){
    
}

void ordenarG(void *arr,int izq, int der, int(*cmp)(const void*,const void*)){
    void **arreglo = (void **)arr;         // para acceder a los campos 
    int limite;
    if (izq>=der) return;
    
    cambiarG(arreglo,izq,(izq+der)/2);
    limite = izq;
    for(int i=izq+1; i<=der; i++){
        if(cmp(arreglo[i],arreglo[izq])<0)    // LO UNICO QUE CAMBIA ES EL CMP 
            cambiarG(arreglo,++limite,i);       // arreglo a punteros void
    }
    cambiarG(arreglo,izq,limite); 
    ordenarG(arreglo,izq,limite-1,cmp);
    ordenarG(arreglo,limite+1,der,cmp);
}
