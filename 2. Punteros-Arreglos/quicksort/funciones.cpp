/* 
 * Proyecto: quicksort
 * Archivo:   funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 17 de abril de 2024, 19:43
 */

#include <iostream>
#include <iomanip> 
using namespace std;
#include "funciones.h"

void sort_tweets(int* dates, char**tweets, char***hashtags){
    int n = 0;
    while(dates[n]) n++;    //saca el num exacto de datos 
    quick_sort(dates, tweets, hashtags, 0 /*indice izq*/, n-1 /*indice der*/);
}

//      listaint,       lista palabras      muchos hashtags por tweet
void quick_sort(int *dates, char **tweets, char*** hashtags,int izq, int der ){
    int pivote, limit;
    if(izq>=der) return;
    
    //1. PIVOTE
    pivote = (izq+der)/2;
    
    //2. intercambia piv con primera pos (IZQUIERDA-PIVOTE)
    swap2(dates[izq],dates[pivote],tweets[izq],tweets[pivote],hashtags[izq],
            hashtags[pivote]);
    //3. INICIALIZAMOS LIMIT
    limit = izq;
    
    //4. FOR AVANZANDO DE IZQ+1 -> COND DE ORDENAMIENTO 
    for(int i=izq+1;i<der;i++){
        //CONDICION
        if(strcmp(tweets[i],tweets[izq])<0){
            limit++;
            //LIMIT- i
            swap2(dates[limit],dates[i],tweets[limit],tweets[i],hashtags[limit],
            hashtags[i]);
        }
    }
    
    //5. SWAP(IZQ - LIMIT) 
    swap2(dates[izq], dates[limit], tweets[izq], tweets[limit], hashtags[izq],
            hashtags[limit]);
    //RECURSIVO CON IZQ LIM DER 
    quick_sort(dates,tweets,hashtags,izq,limit-1);
    quick_sort(dates,tweets,hashtags,limit+1,der);
}

void swap2(int date1,int date2,char *tuit1,char *tuit2,char**hash1,
            char **hash2){
    int aux_int;
    char *aux_tuit;
    char **aaa;
    
    aux_int = date1;
    date1 = date2;
    date2 = aux_int; 
    
    aux_tuit = tuit1;
    tuit1 = tuit2;
    tuit2 = aux_tuit; 
    
    
    aaa = hash1;
    hash1 = hash2;
    hash2 = aaa;
    
}