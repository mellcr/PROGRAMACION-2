/* 
 * Proyecto: CLASES_ERASMO_MEMORIA_EXACTA
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 9 de abril de 2024, 19:23
 */
#include "Utils.h"
#include "Funciones.h"

using namespace std;


int main(int argc, char** argv){
    int *dates; //lista de fechas 
    char **tweets;    //1 tweet -> char , quiero una lista -> char**
    char ***hashtags; ///1 tweet tiene varios hashtags-> char** ->quiero una lista de eso -> char***
    
    
    read_tweets(dates,tweets,"tweets.csv"); 
   read_hashtags(dates,hashtags,"hashtags.csv"); 
    //imprimeRep(dates,tweets,hashtags,"reporte.txt"); 
    display_tweets(dates, tweets, hashtags, "reporte.txt");
    return 0;
}

/*********HASHTAGS*****************************/
 //fecha  hashtag(varios por un mismo tweet)
 //* 
 //* ***************TWEETS********************
 //fecha tweet(uno por dia) 
 //* /