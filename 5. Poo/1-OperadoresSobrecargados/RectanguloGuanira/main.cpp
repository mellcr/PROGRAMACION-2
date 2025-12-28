
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 19 de mayo de 2024, 14:49
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Rectangulo.h"
using namespace std;

/*
 *  UN OBJETO TIENE PROPIEDADES SIMILARES A LAS DE UNA ESTRUCTURA
 */
int main(int argc, char** argv) {
    //       variable
    Rectangulo rectangulo , rect01, *pt, *pt2;
    
    rectangulo.leeDatos();
    rectangulo.mostrarResultados();
    
    rectangulo.setAltura(10);
    rectangulo.setBase(3);
    rectangulo.muestraDatos();
    
    cout<<endl<<"RESULTADOS"<<endl;
    rectangulo.mostrarResultados();
    
    // Se puede hacer pq tiene variables simples 
    //si es un puntero hay problemas (pq abrian dos variables apuntando a lo mismo) 
    rect01 = rectangulo; //se copia byte a byte 
    cout<<endl<<"RESULTADOS COPIADOS: "<<endl;
    rect01.mostrarResultados();
    
    ///////////////// TRABAJANDO CON PUNTEROS //////////////////////
    //para un elemento dinamico del tipo Rectangulo
    cout<<endl<<"RESULTADO DINAMICO: "<<endl;
    pt = new class Rectangulo;
    pt->setBase(5.5);
    pt->setAltura(8.9);
    pt->mostrarResultados();
    cout<<endl;
    // un arreglo 
    cout<<endl<<"RESULTADOS DE UN ARREGLO: "<<endl;
    pt2 = new class Rectangulo[10];
    pt2[3].setAltura(8.8);
    pt2[3].setBase(2.2);
    pt2[3].mostrarResultados();
    

    return 0;
}

