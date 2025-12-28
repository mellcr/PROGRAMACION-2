/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "BibliotecaListaGenerica.h"
#include "ListaRegistrosVoid.h"
using namespace std; 
//LEE REGISTRO -> devuelve un void *
//COMPARA REGISTRO -> devuelve un int -> parametros: compara dos datos tipo void *

void crear_lista(const char* filename,void *&lista_registros, void *(*leer_registro)(ifstream &),
         int (*cmp_registro_str)(const void * , const void *)){
     ifstream arch(filename,ios::in); 
     
     //PASO 1. 
     lista_registros = nullptr; 
     //PASO 2: met exacto
     void *dato; 
     while(true){
         dato = leer_registro(arch); 
         if(dato == nullptr) break; 
         insertarListaAlInicio(dato,lista_registros,cmp_registro_str); 
     }   
 }

void insertarListaAlInicio(void *dato, void *&lista_registros, int (*cmp)(const void *, const void *)) {
    void **nuevoNodo = new void*[2]{}; // Creamos un nuevo nodo
    nuevoNodo[DATO] = dato; // Asignamos el dato al nuevo nodo

    // El siguiente nodo del nuevo nodo será el primer nodo actual de la lista
    nuevoNodo[SIG] = lista_registros;

    // El nuevo nodo ahora será el primer nodo de la lista
    lista_registros = nuevoNodo;
}

void insertarListaAlFinal(void *dato, void *&lista_registros, int (*cmp)(const void *, const void *)) {
    void **nuevoNodo = new void*[2]{}; // Creamos un nuevo nodo

    nuevoNodo[DATO] = dato; // Asignamos el dato al nuevo nodo
    nuevoNodo[SIG] = nullptr; // Establecemos el puntero SIG del nuevo nodo como nullptr, ya que será el último nodo

    // Si la lista está vacía, el nuevo nodo será el primer y único nodo en la lista
    if (lista_registros == nullptr) {
        lista_registros = nuevoNodo;
        return;
    }

    // Encontramos el último nodo de la lista
    void **ultimoNodo = (void **)lista_registros;
    while (ultimoNodo[SIG] != nullptr) {
        ultimoNodo = (void **)ultimoNodo[SIG];
    }

    // Insertamos el nuevo nodo al final de la lista
    ultimoNodo[SIG] = nuevoNodo;
}

 void insertarLista(void *dato,void *&lista_registros,int (*cmp)(const void *, const void *)){
     void **nuevoNodo; 
     void **recorre = (void **)lista_registros, **ant = nullptr; 
     
     nuevoNodo = new void*[2]{};
     nuevoNodo[DATO] = dato; 
     
     while(recorre){
         if(cmp(recorre[DATO],dato)>0)  break; 
         ant = recorre; 
         recorre = (void **)recorre[SIG]; //recorre[SIG] es void *
     }
     nuevoNodo[SIG] = recorre; 
     if(ant ==nullptr) 
         lista_registros = nuevoNodo; 
     else 
         ant[SIG] = nuevoNodo; 
      
 }
 
 void imprime_lista(const char *filename,void *lista_registros, 
         void (*imprimeRegistro)(ofstream &,void *)){
     ofstream arch(filename, ios::out); 
     
     //puntero que recorre
     void **rec = (void **)lista_registros; 
     
     while(rec){
         imprimeRegistro(arch,rec[DATO]); 
         rec = (void**)rec[SIG];  //NO OLVIDAR CASTEAR 
     }
 }
 
 void imprimeRegistro(ofstream &arch,void *dato){
     void **datoCampitos = (void **)dato; 
     int *dni = (int *)datoCampitos[DNI]; 
     char *nomb = (char *)datoCampitos[NOMB]; 
     double *sueldo = (double *)datoCampitos[SUELDO]; 
     
     arch.precision(2);
     arch<<fixed; 
     arch<<left<<setw(10)<<*dni<<left<<setw(60)<<nomb
             <<right<<setw(15)<<*sueldo<<endl;
 }
 
 void eliminar_lista(void *lista_registros, void (*elimina_registro)(void *)){
     void **rec = (void **)lista_registros; 
     void **nodoSale; 
     
     while(rec){
         nodoSale = rec; 
         elimina_registro(rec[DATO]); 
         rec = (void **)rec[SIG]; 
         delete nodoSale; 
     }
     
 }
 
 void elimina_registro(void *dato){
     void **camposDato = (void **)dato; 
     //1. APUNTAR A LOS CAMPOS
     int *dni = (int *)camposDato[DNI]; 
     char *nomb = (char *)camposDato[NOMB]; 
     double *sueldo = (double *)camposDato[SUELDO]; 
     
     //2. DELETEAR campos + dato
     delete dni; 
     delete nomb;
     delete sueldo; 
     delete camposDato; 
 }