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
char *leeCadDelim(ifstream &arch, char delim){
    char *str, buff[200];
    arch.getline(buff,200,delim);
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    
    return str;
}
void crearLista(void *&lista,void* (*lee)(ifstream &),int (*cmp)(const void *, const void *),const char *filename){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout <<"no "<<endl;
        exit(1);
    }
    
    void *dato;
    //1. INICIALIZA LISTA 
    inicializaLista(lista);
    //2. LEE Y LLENA LOS DATOS 
    while(true){
        dato = lee(arch);
        if(dato ==nullptr) break;
       
        insertarListaOrdenado(dato,lista,cmp);
    }
}

void insertarListaOrdenado(void *dato,void *&lista,int (*cmp)(const void *, const void *)){
    void **listaCampos = (void **)lista;
    void **rec = (void **)listaCampos[CAB], **ant = nullptr;
    
    void **nuevoNodo = new void *[2]{};
    nuevoNodo[DAT] = dato;
    
    //INSERTAR ORDENADO
    while(rec){
        if(cmp(rec[DAT],dato)>0) break;
        ant = rec;
        rec = (void **)rec[SIG];
    }
    nuevoNodo[SIG] = rec;
    if(ant==nullptr){
        listaCampos[CAB] = nuevoNodo;
        listaCampos[COLA] = nuevoNodo;
    }else{
        ant[SIG] = nuevoNodo;
    }
    
    //actualizamos la cola
    void **reco = (void **)listaCampos[CAB];
    while(reco[SIG]){
        reco = (void **)reco[SIG];
    }
    if(reco!=nullptr) listaCampos[COLA] = reco;
}

void inicializaLista(void *&lista){
    void **listCola = new void*[2]{};
    listCola[CAB] = nullptr;
    listCola[COLA] = nullptr;
    
    lista = listCola;
}

void imprimeLista(void *lista,void (*imprime)(void *, ofstream &),const char*filename){
    ofstream arch(filename,ios::out);
    void **listacampos = (void **)lista;
    
    if(listacampos[CAB]==nullptr){
        cout <<"la lista ta vacia"<<endl;
    }else{
        //IMPRIMOS LA LISTA YA QUE TIENE VALORES 
        void **rec = (void **)listacampos[CAB];
        while(rec){
            imprime(rec[DAT],arch);
            rec = (void **)rec[SIG];
        }
        
    }
    
}

void uneLista(void *&lista1,void *&lista2){
    //verificaciones (opcional) 
    if (!lista1) {
        lista1 = lista2;
        return;
    }
    if (!lista2) {
        cout <<"lista 2 vacia"<<endl;
        return;
    }
    void **camposLista1 = (void **)lista1;
    void **camposLista2 = (void **)lista2;
    
    void **nodoCola1 = (void **)camposLista1[COLA];
    void **nodoCab2 = (void **)camposLista1[CAB];
    
    //cola1 con cabeza de 2
    nodoCola1[SIG] = nodoCab2;
    //actualizamos la colita del 1
    camposLista1[COLA] = camposLista2[COLA];
    //lista 2 ahora apuntara a null
    lista2 = nullptr;
}