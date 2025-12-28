/* 
 * Proyecto: CLASE_ERASMO_MEM_INCREMENTOS
 * Archivo:   funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 14 de abril de 2024, 16:56
 */

#include "Utils.h"
#include "funciones.h"
using namespace std;
#define INCREMENTO 5


char *read_str(ifstream &arch){
    char *str,aux[100];
    arch.getline(aux,100); //lee hasta el cambio de linea :) 
    int len = strlen(aux);
    str = new char [len+1];
    strcpy(str,aux);
    return str; 
}

void read_tweets(int *&dates,char **&tweets, const char *filename ){
    ifstream arch(filename,ios::in);
    //VARIABLES AUX LECT
    int date;
    char *tuit;
    //VARIABLES MEMORIA POR INCREMENTOS 
    int tweets_size=0,capacity=0;
    dates = nullptr; //el primer puntero apunta a null -> arrastra a los demas  
    tweets = nullptr;
    while(true){
        arch>>date;
        if(arch.eof()) break;
        arch.get();
        tuit = read_str(arch);
        
        if(capacity ==tweets_size){ //ini 0=0  -> AUMENTA CAPACIDAD 
            reserva_memoria_incrementos(dates,tweets,tweets_size,capacity); //le paso ORIGINALES -> los quiero reservar 
        }
        //sale con tam = 1 entonces en pos = 0
        dates[tweets_size-1] = date;
        tweets[tweets_size-1] = tuit;
        tweets_size++;
    }
}

void reserva_memoria_incrementos(int *&dates,char **&tweets,int &tweets_size,
        int &capacity){
    //1. AUXILIARES DINAMICOS
    int *aux_dates;
    char **aux_tweets;
    // capacity==size -> 2. AUMENTAR CAPACIDAD 
    capacity += INCREMENTO;
    
    //CASOS: AL INICIO Y CUANDO YA HAY VALORES
    //3. INICIO
    if(dates ==nullptr){
        //reservo mem original
        dates = new int [capacity]{};
        tweets =new char*[capacity]{};
        tweets_size =1; //primer elemento leido
    }else{ //4. CUANDO HAY DATOS 
        //UTILIZO AUX 
        aux_dates =new int [capacity]{}; 
        aux_tweets = new char *[capacity]{}; 
        //copio valores a aux
        for(int i=0; i<tweets_size;i++){
            aux_dates[i] = dates[i];
            aux_tweets[i] = tweets[i];
        }
        //los boto fuera del salon 
        delete dates;
        delete tweets;
        //les digo que vuelvan a pasar pq ya hay espacios
        dates = aux_dates;
        tweets = aux_tweets;
    }
}
int lookup(int date,int *dates){
    for(int i=0;dates[i];i++){
        if(date == dates[i]) return i;
    }
    return -1;
}
void read_hashtags(int *&dates,  char ***&hashtags, const char *filename){
    ifstream arch(filename,ios::in);
    //VARIABLES AUX
    int date,pos;
    //char *hashtag_lect;
    //MEM POR INCREMENTO 
    int tweet_size =0, hashtagFila[20]{},capacityFila[20]{};
    
    while(dates[tweet_size]) tweet_size++;
    
    //RESERVAMOS MEMORIA VERTICAL (lista para todos los tweets)
    hashtags = new char **[tweet_size+1]{}; 
    
    while(true){
        arch>>date;
        if(arch.eof()) break;
        arch.get();
        pos = lookup(date,dates); 
        if(pos!=-1){ //LO ENCUENTRA 
            add_hashtag(arch,hashtags[pos],hashtagFila[pos],capacityFila[pos]);
        }else{ // LO DESCARTA 
            while(arch.get()!='\n');
        }
        
    }
}

void reserva_memoria_incrementos(ifstream &arch,char **&hashtags,
        int &hashtagFila,int &capacityFila){
 
    //1. AUX DINAMICOSSS
    char **hastags_aux;
    //2. AUMENTO CAPACIDAD
    capacityFila += INCREMENTO;
    if(hashtags==nullptr){ //inicio
        //reservo mem
        hashtags = new char*[capacityFila]{};
        hashtagFila = 1;//primer elem leido 
    }else{
        //guardo en mis aux
        hastags_aux = new char*[capacityFila]{};
        //copio valores a aux
        for(int i=0;hashtags[i];i++){
            hastags_aux[i] = hashtags[i];
        }
        //le digo q se vaya del salon
        delete hashtags;
        //le digo q entre pq ya hay mas sitios
        hastags_aux = hashtags;
        
    }
        
}

//                                                        numDat          capacity
void add_hashtag(ifstream &arch,char **&hashtags,int &hashtagFila,int &capacityFila){
    char *one_hashtag;
    one_hashtag = read_str(arch); //lo leo 
    
    if(hashtagFila==capacityFila){
        reserva_memoria_incrementos(arch,hashtags,hashtagFila,capacityFila);
    }
    //hashtagFila sale con el valor de 1 al inicio
    hashtags[hashtagFila-1] = one_hashtag;
    hashtagFila++;
}




void display_hashtags(char** hashtags, ofstream &out){
    for(int i=0;hashtags[i];i++)
        out<<right<<setw(20)<<hashtags[i]<<endl;
}

void display_tweets(int *dates, char **tweets, char ***hashtags, const char *filename){
    ofstream arch(filename,ios::out);
    //char *tuits[70] = char **tweets;
    arch <<setw(70)<< "REPORTE DE PRUEBA "<<endl; 
    char **hashtags_aux;
    for(int i=0;dates[i];i++){
        arch <<left<< setw(20)<<dates[i]<<setw(60)<<tweets[i]<< endl; 
        if(hashtags[i]){
            display_hashtags(hashtags[i],arch); 
        }
        arch <<endl;
    }
    
}