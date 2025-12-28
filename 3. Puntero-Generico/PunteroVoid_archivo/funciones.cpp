/* 
 * Proyecto: aprendiendoPunteroVoid
 * Archivo:   funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 21 de abril de 2024, 12:59
 */

#include <iostream>
#include <iomanip> 
#include <fstream> 
#include <cstring>
#include "funciones.h"
using namespace std;
enum Registro {DNI,NOMB,SUELD};
//ojo se guardan valores consecutivos
//enum Registro {DNI=12,NOMB,SUELD};  12   13 14
//enum Registro {DNI,NOMB=12,SUELD};  0   12  13

void leeRegistro(void *&persona){
    ifstream arch("prueba.txt",ios::in);
    //1.VARIABLES DINAMICAS AUX
    int *dni,dni_lect;
    char *nombre, buff[100]; //aux para leer 
    double *sueldo;
    //2.REGISTRO
    void **registro;
    //////////////////////////////lectura///////////////////////////////
    arch >> dni_lect;
    if(arch.eof()){
        persona = nullptr;
        return;
    }
    dni = new int;
    *dni = dni_lect;
    arch.get(); //saca coma
    arch.getline(buff,100,',');
    nombre = new char[strlen(buff)+1];
    strcpy(nombre,buff);
    sueldo = new double;
    arch>>*sueldo; //guardo de frente en su valor pq ya le reserve espacio
    /////////////////////////////////////////////////////////////////
    registro = new void*[3]; //de 3 elementos
    registro[DNI] = dni;
    registro[NOMB] = nombre;
    registro[SUELD] = sueldo;
    
    persona = registro; //para que persona salga apuntando a eso
}
void imprimeRegistro(void *persona){
    int *dni;
    char *nombre;
    double *sueldo;
    
    //1. REGISTRO APUNTA A PERSONA 
    void **registro = (void**)persona; //PARA QUE REGISTRO PUEDA ACCEDER A INDICES
    //2. ASIGNAR A LAS VAL AUX CON CAST
    dni = (int *)(registro[DNI]);
    nombre = (char *)(registro[NOMB]);
    sueldo = (double *)(registro[SUELD]);
    
    cout.precision(2);
    cout<<fixed;//          * accede al valor
    cout << left<<setw(15)<<*dni<<setw(50)<<nombre<<setw(15)
            <<*sueldo<<endl; 
}

void liberaEspacios(void *persona){
    int *dni;
    char *nombre;
    double *sueldo;
    void **registro = (void**)persona; //ya puedo ind
    //PUNTEROS AUX APUNTANDO A CADA UNO DE ELLOS
    dni = (int *)(registro[DNI]);
    nombre = (char *)(registro[NOMB]);
    sueldo = (double *)(registro[SUELD]);
    //BORRAMOS TODO 
    delete dni;
    delete nombre;
    delete sueldo;
    delete registro;
}


void *leeRegistro(ifstream &arch){
    
    int *dni,dni_lect;
    char *nombre, buff[100]; //aux para leer 
    double *sueldo;
    //2.REGISTRO
    void **registro;
    //////////////////////////////lectura///////////////////////////////
    arch >> dni_lect;
    if(arch.eof()) return nullptr;
    dni = new int;
    *dni = dni_lect;
    arch.get(); //saca coma
    arch.getline(buff,100,',');
    nombre = new char[strlen(buff)+1];
    strcpy(nombre,buff);
    sueldo = new double;
    arch>>*sueldo; //guardo de frente en su valor pq ya le reserve espacio
    /////////////////////////////////////////////////////////////////
    registro = new void*[3]; //de 3 elementos
    registro[DNI] = dni;
    registro[NOMB] = nombre;
    registro[SUELD] = sueldo;    
    
    return registro; 
    //esta funcion que devuelve void* puede devolver cualquier dato
    //el casteo lo hace c++ 
}

void leeDatos(void *&pers,int &numPer){
    ifstream arch("prueba.txt",ios::in);
    
    void **personas, *buff[100],*p;
    
    numPer =0;
    while(true){
        p=leeRegistro(arch);
        if(p==nullptr) break;
        buff[numPer] = p;
        numPer++;
    }
    
    personas = new void*[numPer];
    for(int i=0;i<numPer;i++){
        personas[i] = buff[i];
    }
    
    pers = personas;  //voi* apunta a un arr void* -> void* apunta a cualquier cosa
}

void imprimeDatos(void *per,int numPer){
    void **personas = (void**)per;
    
    for(int i=0;i<numPer;i++){
        imprimeRegistro(personas[i]);
    }
}

//QUICK SORT
void ordenar(void *per,int izq,int der){
    void **personas = (void **)per;
    int limite;
    if(izq>=der) return;
    cambiar(personas[izq],personas[(izq+der)/2]);
    limite = izq;
    for(int i=izq+1;i<=der;i++)
        if(compararNomb(personas[i],personas[izq])<0)
            cambiar(personas[++limite],personas[i]);
    cambiar(personas[izq],personas[limite]);
    
    ordenar(personas,izq,limite-1);
    ordenar(personas,limite+1,der); 
}

void cambiar(void *&a,void *&b){
    void *aux;
    aux = a;
    a = b;
    b = aux;
}

//compara un registro 
int comparar(void *perI,void *perJ){
    void **personaI=(void**)perI,  
         **personaJ=(void**)perJ;//ya podemos acceder a sus indices
    
    //lo ordenamos por el sueldo y de mayor a menor 
    double *sueldoI= (double *)(personaI[SUELD]), 
        *sueldoJ= (double *)(personaJ[SUELD]); // lo casteamos pq personaI es un void*
    
    //COMPARAMOS
    return *sueldoJ- *sueldoI; //*accede al valor 
}

int compararNomb(void *perI,void *perJ){
    void **personaI=(void**)perI,  
         **personaJ=(void**)perJ;//ya podemos acceder a sus indices
    
    //lo ordenamos por el sueldo y de mayor a menor 
    char *nombreI= (char *)(personaI[NOMB]), 
        *nombreJ= (char *)(personaJ[NOMB]); // lo casteamos pq personaI es un void*
    
    //COMPARAMOS
    return strcmp(nombreI,nombreJ);
}