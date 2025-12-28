/* 
 * Proyecto: CLASE_ERASMO_MEM_INCREMENTOS
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 14 de abril de 2024, 16:43
 */

#include "Utils.h"
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    int *dates;
    char **tweets;
    char ***hashtags;
    read_tweets(dates,tweets, "tweets.csv");
    //read_hashtags(dates,hashtags, "hashtags.csv");
    display_tweets(dates, tweets, hashtags, "reporte.txt");
    //sort_tweets(dates, tweets, hashtags);
    //display_tweets(dates, tweets, hashtags, "reporte_ordenado.txt");
    
    
    
    return 0;
}

