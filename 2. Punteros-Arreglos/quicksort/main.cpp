/* 
 * Proyecto: quicksort
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 17 de abril de 2024, 19:39
 */

#include <iostream>
#include <iomanip> 
using namespace std;
#include "funciones.h"

int main(int argc, char** argv) {
    int *dates;
    char **tweets;
    char ***hashtags;
    
    sort_tweets(dates, tweets, hashtags);
    
    return 0;
}

