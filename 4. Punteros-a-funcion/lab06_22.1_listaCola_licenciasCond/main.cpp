/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 2 de mayo de 2024, 18:02
 */

#include "Utils.h"
#include "BibliotecaListaGenerica.h"
#include "listaConRegistro.h"
#include "ListaConEnteros.h"
using namespace std;

int main(int argc, char** argv) {
    void *lista1,  *lista2;
    
    crearLista(lista1,leenum,cmpnum,"RegistroDeFaltas1.csv");
    crearLista(lista2,leenum,cmpnum,"RegistroDeFaltas2.csv");
    imprimeLista(lista1,imprimenum,"replist1.txt");
    uneLista(lista1,lista2);
    //imprimeLista(lista1,imprimenum,"repFusionEnteros.txt");
            
    crearLista(lista1,leeregistro,cmpregistro,"RegistroDeFaltas1.csv");
    imprimeLista(lista1,imprimeregistro,"repReg.txt");
    
    
    return 0;
}

