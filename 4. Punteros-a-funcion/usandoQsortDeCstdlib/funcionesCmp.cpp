/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "Utils.h"
using namespace std;
#include "funcionesCmp.h"
enum Reg{DNI,NOMBRE,SUELDO};

int intCmp(const void *a, const void*b){
    int *ai = (int *)a;
    int *bi = (int *)b;
    
    return *ai - *bi;
}

int miStrCmp(const void *a, const void*b){
    char **ai = (char **)a, **bi = (char **)b;
    return strcmp(*ai, *bi); //apuntando al elemento(1 cadena) del arreglo 
}

int voidCmpSueldo(const void *a, const void*b){
    void **ai = (void **)a, **bi = (void **)b;
    //es similar a -> "acceder a campos" -> ai ahora es void *
    void **regA= (void**)(ai[0]);
    void **regB = (void **)(*bi);
    
    double *sueldoA = (double *)(regA[SUELDO]),*sueldoB= (double *)(regB[SUELDO]);
    return *sueldoA- *sueldoB; //ORDENA DE MENOR A MAYOR
   // return *sueldoB- *sueldoA; //ORDENA DE MAYOR A MENOR
}


int voidCmpNombres(const void *a, const void*b){
    void **ai = (void **)a, **bi = (void **)b;
    //es similar a -> "acceder a campos" -> ai ahora es void *
    void **regA= (void**)(ai[0]);
    void **regB = (void **)(*bi);
    
     char *nombA = (char *)(regA[NOMBRE]),*nombB= (char *)(regB[NOMBRE]);
    return strcmp(nombA, nombB); //el cod ascii de a es menor que el de z jiji (ordena de menor a mayor)-> alfabeticamente A aparecera arriba
}

int voidCmpDni(const void *a, const void*b){
    void **ai = (void **)a, **bi = (void **)b;
    //es similar a -> "acceder a campos" -> ai ahora es void *
    void **regA= (void**)(ai[0]);
    void **regB = (void **)(*bi);
    
    int *dniA = (int *)(regA[DNI]),*dniB= (int *)(regB[DNI]);
    return *dniA-*dniB; 
}