
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 19 de mayo de 2024, 17:04
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "RectanguloMS.h"
using namespace std;

/*
 *  RECTANGULO POR METODO DE SELECTORES 
 */
int main(int argc, char** argv) {
    RectanguloMS rectangulo, r1(10,5,"Segundo Rectangulo");
    RectanguloMS *ptR, *ptR2; 
    
    rectangulo.setNombre("Primer Rectangulo");
    rectangulo.setAltura(10);
    rectangulo.setBase(3);
    rectangulo.mostrarResultados();
     
    //char *cad;
    //getline no gesta mem 
    //cin.getline(cad,100); -> lo dejaria en cualquier parte 
    
//    int a=23;
//    const int b=23;
//    a = 22;
//    //b=22; -> no se puede modificar el valor 
//    
//    ClaseFecha f1;
//    f1.setDia(12);// -> podre cambiarlo
//            
//    const ClaseFecha f2; //con constructor se inicializa y no se podra modificar
//    f2.setDia(20); //BOTA ERROR
//    int dia  = f1.getDia();
    
    r1.mostrarResultados(); 
    
    //llama al c. por defecto!! 
//    ptR = new RectanguloMS; 
//    delete ptR;
    //por referencia 
    ptR2 = new RectanguloMS(11,3.7,"3ra Prueba");
    ptR2->mostrarResultados();  //al ser un puntero, para llamar al método tengo que  llegar a la variable referenciada por la flecha
    delete ptR2;    //como son punteros, ambos se tienen q deletear ( no llaman al destructor automaticamente) 
    
    
    //ARREGLO! 
    ptR = new RectanguloMS[5]; 
    //delete ptR; //borra el primer elemento del arreglo!!! 
    delete []ptR; //borra TODOS los elementos
    
    //EMPLEAMOS EL CONSTRUCTOR COPIA QUE NOS AYUDA CON EL PROBLEMA QUE HABIA CUANDO EN UN ATRIB HAY PUNTEROS
    RectanguloMS  inst1 = rectangulo;
    
    
    return 0;
}


//video 12 

