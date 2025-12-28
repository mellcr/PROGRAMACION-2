/* 
 * Proyecto: CLASES_ERASMO_MEMORIA_EXACTA
 * Archivo:   Funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 9 de abril de 2024, 19:25
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
using namespace std; 

void read_hashtags(int *dates,char ***&hashtags,const char*filename);
int lookup(int date,int *dates); 
void cut(char **&hashtags, int n); 
void add_hashtag(ifstream &input,char **hashtags, int & n_hashtags); 
void read_tweets(int *&dates,char **&tweets,const char*filename);
char * read_str(ifstream &input); 
void display_hashtags(char** hashtags, ofstream &out);
void display_tweets(int *dates, char**tweets, char***hashtags, const char *filename);
void imprimeRep(int *dates,char **tweets,char ***hashtags,const char *filename);


#endif /* FUNCIONES_H */

