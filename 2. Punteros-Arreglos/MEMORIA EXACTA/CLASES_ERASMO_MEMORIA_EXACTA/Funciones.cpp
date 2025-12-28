/* 
 * Proyecto: CLASES_ERASMO_MEMORIA_EXACTA
 * Archivo:   Funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 9 de abril de 2024, 19:25
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Utils.h"
#include "Funciones.h"
using namespace std; 
#define NOT_FOUND -1

char * read_str(ifstream &input){
    char * str; //cad tipÃ³ char*
    char buffer[100]; //cad para lectura
    input.getline(buffer,100); //lee hasta el salto de linea 
    //ASIGNO ESPACIO DE MEMORIA 
    str = new  char[strlen(buffer)+1]{}; //+1 para el caracter nulo     
    strcpy(str,buffer);
    
    return str; //retorno la cad char*
}

void read_tweets(int *&dates,char **&tweets,const char*filename){
    ifstream input(filename,ios::in); //apertura del archivo 
    
    //1. BUFFER ESTATICO
    int bufferDates[20]{}, tweet_size=0,date;
    char *bufferTweets[20]{}; //char * 
    
    //2. TAM REAL DE DATOS
    //3. LECTURA Y LLENADO DE BUFFERS
    //tweet_size = 0; 
    while(true){
        input>>date; 
        if(input.eof()) break; 
        input.get();  //coma
        //guardo en mis buffers
        bufferDates[tweet_size] = date; 
        bufferTweets[tweet_size] = read_str(input); 
        //luego de leer cad y date
        tweet_size++; 
    }
    
    //4. RESERVA DE MEMORIA EXACTA EN ARR_DIN+ (recordar q baja un nivel) 
    dates = new int[tweet_size+1]{};    //crea esp exacto para la lista de dates*
    tweets = new char*[tweet_size+1]{}; //crea esp exacto para la lista de char**
    //5. COPIA DE DATOS ESTATICOS A ARR_DIN 
    for(int i=0; i<tweet_size; i++){
        dates[i] = bufferDates[i]; 
        tweets[i] = bufferTweets[i]; //pq no hace con strcpyh
    }
}

int lookup(int date,int *dates){
    //busco en el arreglo
    for(int i=0;dates[i]; i++){  //dates[i] es 1 hasta q no tenga datos 
        if(date == dates[i]) return i; 
    }
    return NOT_FOUND; 
}

//                                              indica el num de hash en esa fila 
void add_hashtag(ifstream &input,char **hashtags, int & n_hashtags){
    //aca leo el hastagh y lo guardo en la posicion de acuerdo a la fecha 
    char*hashtag; 
    hashtag = read_str(input); 
    //lo guardo 
    hashtags[n_hashtags] = hashtag; //asigna punteros OJO
    n_hashtags++; 
}

void cut(char **&hashtags, int n){
    char **hashatg_aux; 
    
    if(n!=0){ //1 2 3 4 5... 20
        //reservo un espacio EXACTO al arr aux
        hashatg_aux = new char *[n+1]{}; 
        for(int i=0; i<n; i++){
            hashatg_aux[i] = hashtags[i]; 
            delete hashtags; 
            hashtags = hashatg_aux; 
        }
        
        
    }else{ //n==0 -> no tiene hashtags
        delete hashtags; 
        hashtags = nullptr; 
    }
    
    
}


void read_hashtags(int *dates,char ***&hashtags,const char*filename){
    ifstream input(filename,ios::in); //aperturamos el archivo
    int tweets_size=0,date,pos;
    int n_hashtags_fila[20]{};    //este arreglo guarda el num de hashtags exactos para cada fila
    char aux[60]; 
    
    //calculamos el tamaÃ±o exacto de datos (fechas) que tenemos -> recuerda: solo se puede tuitear una vez al dia 
    while(dates[tweets_size]) tweets_size++; 
    //reserva de memoria de hashtags
    hashtags = new char**[tweets_size+1]{}; 
    for(int i=0; i<tweets_size; i++){
        hashtags[i] = new char*[20]; //
    }
    
    while(true){
        input >> date; 
        if(input.eof()) break; 
        input.get(); 
        
        pos = lookup(date,dates); 
        if(pos!=NOT_FOUND){
            //leemos el hashtag y lo aÃ±adimos en la lista de hashtags por ese dia 
            //hashtag en la pos (le pasa el hashtag en ese dia -> oracion 
            add_hashtag(input,hashtags[pos], n_hashtags_fila[pos]); 
        }else{
            input.getline(aux,60); //descarta y se come el salto de linea 
        }
    }
    
    //RECORTE DE MEMORIA 
    for(int i=0; hashtags[i]; i++){
        cut(hashtags[i],n_hashtags_fila[i]); 
    }
    
}


void imprimeRep(int *dates,char **tweets,char ***hashtags,const char *filename){
    
}
void display_hashtags(char** hashtags, ofstream &out){
    for(int i=0;hashtags[i];i++)
        out<<right<<setw(20)<<hashtags[i]<<endl;
}

void display_tweets(int *dates, char**tweets, char***hashtags, const char *filename){
    ofstream out(filename,ios::out);
    for(int i=0; dates[i] ;i++){
        out<<left<<setw(10)<<dates[i]<<tweets[i]<<endl;
        if(hashtags[i])
            display_hashtags(hashtags[i], out);
        else
            out<<"No tiene hashtags"<<endl;
    }
}

/***********PASOS: MEMORIA ESTATICA****************/
// 1. buffer estatico
//2. tamaÃ±o real de datos
//3. Lectura y llnado de buffers
//4. reserva de memoria exacta a arr_din
//5. copia de los datos estaticos a arr_din 
