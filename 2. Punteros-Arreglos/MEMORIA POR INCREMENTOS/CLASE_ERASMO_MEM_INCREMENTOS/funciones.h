/* 
 * Proyecto: CLASE_ERASMO_MEM_INCREMENTOS
 * Archivo:   funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 14 de abril de 2024, 17:37
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
using namespace std;

void read_hashtags(int *&dates,  char ***&hashtags, const char *filename);
void display_tweets(int *dates, char **tweets, char ***hashtags, const char *filename);
char *read_str(ifstream &arch);
void read_tweets(int *&dates,char **&tweets, const char *filename );
void reserva_memoria_incrementos(int *&dates,char **&tweets,int &tweets_size,
        int &capacity);
int lookup(int date,int *dates);
void add_hashtag(ifstream &arch,char **&hashtags,int &hashtagFila,int &capacityFila);
void display_hashtags(char** hashtags, ofstream &out); 



#endif /* FUNCIONES_H */

