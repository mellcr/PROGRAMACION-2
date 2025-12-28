/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 27 de abril de 2024, 16:28
 */

#include "Utils.h"
#include "funcionesVoid.h"
#include "funcionesCmp.h"
using namespace std;
#include <cstdlib> 
 


void imprimeArr(const char **arr,int n){
    cout <<"ARREGLO DE CHARS: ";
    for(int i=0;i<n;i++){
        cout <<left<<setw(20)<<arr[i];
    }
    cout <<endl;
}

int main(int argc, char** argv) {
    int arr[50]={10,24,52,87,9,4,75},n=7;
    qsort(arr,n,sizeof(int),intCmp);
     cout <<"ENTEROS: ";
    for(int i=0;i<n;i++){
        cout <<left<<setw(4)<<arr[i];
    }
    cout <<endl;
    
    //////////////////////// cadena de caracteres //////////////////////////////////
     const char *personas[]={"mell","dri","honguitojoto"};  //arreglo de cadenas -> ELEMENETO PRIMARIO: char*
    int nd=3;
    qsort(personas,nd,sizeof(char *),miStrCmp);
    imprimeArr(personas,nd);
      for(int i=0;i<60;i++) cout.put('-');
    cout<<endl;
    
    /////////////////////////////////// registro (tipo void *) /////////////////////////////
    void *personal;
    int np;
    leerDatos(personal,np);
    //imprimirDatos(personal,np);
    //qsorts
   //qsort(personal,np,sizeof(void *),voidCmpSueldo);
    //qsort(personal,np,sizeof(void *),voidCmpNombres);
    qsort(personal,np,sizeof(void *),voidCmpDni);
    imprimirDatos(personal,np);
    
    
    return 0;
}

