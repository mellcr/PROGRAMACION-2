/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "listas_genericas.h"
using namespace std;

//enum Registro{COD,NOMB,ROL,CAT,PUNT};
//enum Nodo{DAT,SIG};
//enum Lista{CAB,COLA};
void eliminar_lista_heroes_repetidos(void *&lista_heroes, void (*eliminar_registro)(void *&)){
    void **lista = (void **)lista_heroes; //ya puedo acceder a la cabeza 
    void **aux = (void **)lista[CAB]; //estoy en el primer NODO 
    void **sig = nullptr; 
    
    while(aux){
        sig = (void **)aux[SIG]; 
        if(sig!=nullptr and compararNombres(aux[DAT],sig[DAT])==0){ //b b
            aux[SIG] = sig[SIG]; 
            eliminar_registro(sig[DAT]);
            delete sig; 
        }else{
            aux = (void **)aux[SIG]; 
        }
    }
    
}

//recibe el puntero al registro 
void eliminar_registro(void *&registro){
    //acceder a los campos del rgistro
    void **camposreg = (void **)registro; 
    
    int *cod = (int *)camposreg[COD]; 
    char *nomb = (char *)camposreg[NOMB]; 
    char *rol = (char *)camposreg[ROL]; 
    char *cat = (char *)camposreg[CAT]; 
    double *puntaj = (double *)camposreg[PUNT]; 
    
    //deleteamos jiji
    delete cod; 
    delete nomb; 
    delete rol; 
    delete cat; 
    delete puntaj; 
    delete camposreg; 
}

int compararNombres(void *regA, void *regB){
    //acceder a los campos del registro 
    void **camposA = (void **)regA;
    void **camposB = (void **)regB;
    
    char *nombA = (char *)camposA[NOMB]; 
    char *nombB = (char *)camposB[NOMB]; 
    
    return strcmp(nombA,nombB);
}


void crear_lista_heroes(void *arreglo_heroes,void *&lista_heroes,void* (*leer_heroe)( void*)){
    void **arrHeroes = (void **)arreglo_heroes;
    void *datoHeroe;
    
    //1. INICIALIZAR LISTA
    construyeListaCola(lista_heroes);
    
    //2. LEER LOS DATOS Y CREAR LOS NODOS 
    
    for(int i=0; arrHeroes[i];i++){
        datoHeroe = leer_heroe(arrHeroes[i]);
        insertarListaFinal(lista_heroes,datoHeroe);
    }
    
}
//ENCOLAR  - insertar al final
//enum Nodo{DAT,SIG};
void insertarListaFinal(void *&lista_heroes,void *datoHeroe){
    void **listacola = (void **)lista_heroes;
    void **punteroFinal ;

    //CREAMOS NODO
    void **nuevoNodo = new void *[2]{};
    nuevoNodo[DAT] = datoHeroe;
    nuevoNodo[SIG] = nullptr;
    
    if(esColaVacia(lista_heroes)){ //insertar al incio
        listacola[CAB] = nuevoNodo;
    }else{
        punteroFinal = (void**)listacola[COLA];
        punteroFinal[SIG] = nuevoNodo;
    }
    listacola[COLA] = nuevoNodo;
    
}

void imprimir_lista_heroes(const char *filename,void *lista_heroes,void (*imprimir_registro_heroes)(void *, ofstream &)){
    ofstream arch(filename,ios::out);
    
    void **rec, **nodo;
    void **listaCampos = (void **)lista_heroes;
    
    if(!esColaVacia(lista_heroes)){
        rec = (void **)listaCampos[CAB];
        while(rec){
            nodo = (void **)rec;
            
            imprimir_registro_heroes(nodo[DAT],arch);
            
            rec = (void **)nodo[SIG];
        }
    }
}

void imprimir_registro_heroes(void *registro, ofstream &arch){
    void **registroHeroe = (void **)registro;
    char *nomb = (char *)registroHeroe[NOMB];
    char *rol = (char *)registroHeroe[ROL];
    char *categ = (char *)registroHeroe[CAT];
    double *puntaj = (double *)registroHeroe[PUNT];
    int *cod = (int *)registroHeroe[COD];
    arch.precision(2);
    arch<<fixed;
    arch<<left <<setw(20)<<nomb<<setw(10)<<rol<<setw(10)<<categ<<setw(10)<<*puntaj<<setw(10)<<*cod<<endl;
}

bool esColaVacia(void *lista){
    void **listaCola = (void **)lista;
    if(listaCola[CAB]==nullptr) return true;
    else return false;
}
void construyeListaCola(void *&lista_heroes){
    void **listaCola = new void *[2]{};
    listaCola[CAB] = nullptr;
    listaCola[COLA] = nullptr;
    
    lista_heroes = listaCola;
}

//enum Nodo{DAT,SIG};
//enum Registro{COD,NOMB,ROL,CAT,PUNT};
void* leer_heroe(void *heroe){
    void **regHeroe = (void **)heroe;
    int *codHeroe = (int *)regHeroe[COD];
    char *nombHeroe = (char *)regHeroe[NOMB];
    char *catHeroe = (char *)regHeroe[CAT];
    char *rolHeroe = (char *)regHeroe[ROL];
    double *puntHeroe = (double *)regHeroe[PUNT];
    
    int *cod = new int;
    *cod = *codHeroe;
    char *nomb = new char[strlen(nombHeroe)+1]{};
    strcpy(nomb,nombHeroe);
    char *rol = new char[strlen(rolHeroe)+1]{};
    strcpy(rol,rolHeroe);
    char *categoria = new char[strlen(catHeroe)+1]{};
    strcpy(categoria,catHeroe);
    double *punt = new double;
    *punt = *puntHeroe;
    
    void **nuevoReg = new void *[5]{};
    nuevoReg[COD]= cod;
    nuevoReg[NOMB]= nomb;
    nuevoReg[ROL]= rol;
    nuevoReg[CAT]= categoria;
    nuevoReg[PUNT]= punt;
    
    return nuevoReg;
}