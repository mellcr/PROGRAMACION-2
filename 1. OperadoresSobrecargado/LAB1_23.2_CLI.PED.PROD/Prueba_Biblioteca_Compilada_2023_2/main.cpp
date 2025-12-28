/* 
 * Proyecto: Prueba_Biblioteca_Compilada_2023_2
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 31 de marzo de 2024, 13:24
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Funciones.h"
#include "Estructuras.h" //este es el arch de la biblioteca 
using namespace std;



//en este proyc emplearemos la biblioteca creada ya enlazada
int main(int argc, char** argv) {
    //1. crear los archivos de rep de prueba
    ifstream arch("prueba.txt",ios::in);
    ofstream archRep("reporte.txt",ios::out);
    
    struct Cliente c;
    struct Producto pro; 
    struct Cliente C[2]{}; 
    struct Producto P[2]{"XXXXXXX"}; //lo inicializa en ese valor
    struct Pedido ped; 
    
    arch >> c; 
    arch.get();  //come el salto de linea 
    arch >> pro;
    //arch.get(); 
    arch >> ped; 
    ped.precioProducto = pro.precio; 
    C[0] = c; 
    C[1].dni=0; //le doy un tope al ult elemento struct de mi arreglo 
    P[0] = pro; 
    strcpy (P[0].codigo,pro.codigo);
    strcpy (P[1].codigo,"XXXXXXX");
    //agregamos los productos 
    C+=ped; 
    P+=ped; 
    
    //imprimimos
    archRep << C[0]; 
    archRep<< P[0]; 
        
    

    return 0;
}

