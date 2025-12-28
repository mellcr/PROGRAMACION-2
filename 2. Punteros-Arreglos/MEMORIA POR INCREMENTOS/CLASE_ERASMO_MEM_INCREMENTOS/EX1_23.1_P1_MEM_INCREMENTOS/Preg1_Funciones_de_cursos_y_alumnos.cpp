/* 
 * Proyecto: EX1_23.1_P1_MEM_INCREMENTOS
 * Archivo:   Preg1_Funciones_de_cursos_y_alumnos.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 15 de abril de 2024, 16:02
 */

#include "Utils.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
using namespace std;

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,
        const char * nombCur, const char *nombEsc){
    ifstream archCur(nombCur,ios::in);
    ifstream archEsc(nombEsc,ios::in);
    
    //1. VAR AUX LECTURA 
    char **registro; 
    
    double credCur; //para guardarlo en la otra pila 
     
    //2. VARIABLES MEM POR INCREMENTOS
    int capacity = 0, numDat=0; 
    
    //3. LECTURA Y AUMENTO DE CAPACIDAD CAPACITY=NUMDAT
    while(true){
        registro = leeRegistro(archCur,credCur); 
        
        
        
        if(numDat == capacity){
            reserva_memoria_incrementos(cursos,codCur,name_curso,credCur,
                    codProf,nombProf,capacity); 
        }
        
        numDat++; 
    } 
    //4. RESERVA DE MEM INCREMENTOS :)) 
    //5. GUARDAR EN ORIGINAL 
    
}

char **leeRegistro(ifstream &archCur,double &credCur){
    char *codCur, *name_curs, *nombProf; 
    int codProf;
    
    
    
    archCur.getline(codCur,7,',');
    if(archCur.eof()) return nullptr; 
    archCur.getline(name_curso,60,','); 
    archCur>>credCur>>c>>codProf>>c; 
    archCur.getline(nombProf,60); //lee hasta el salto de liena :))) 
        
}

    //1. VAR AUX LECTURA 
    //2. VARIABLES MEM POR INCREMENTOS
    //3. LECTURA Y AUMENTO DE CAPACIDAD CAPACITY=NUMDAT
    //4. RESERVA DE MEM INCREMENTOS :)) 
    //5. GUARDAR EN ORIGINAL 

//
// ifstream arch(filename,ios::in);
//    //VARIABLES AUX LECT
//    int date;
//    char *tuit;
//    //VARIABLES MEMORIA POR INCREMENTOS 
//    int tweets_size=0,capacity=0;
//    dates = nullptr; //el primer puntero apunta a null -> arrastra a los demas  
//    tweets = nullptr;
//    while(true){
//        arch>>date;
//        if(arch.eof()) break;
//        arch.get();
//        tuit = read_str(arch);
//        
//        if(capacity ==tweets_size){ //ini 0=0  -> AUMENTA CAPACIDAD 
//            reserva_memoria_incrementos(dates,tweets,tweets_size,capacity); //le paso ORIGINALES -> los quiero reservar 
//        }
//        //sale con tam = 1 entonces en pos = 0
//        dates[tweets_size-1] = date;
//        tweets[tweets_size-1] = tuit;
//        tweets_size++;
//    }
    
void pruebaDeCargaDeAlumnos(int *alumnos_cod,int **alumnos,char***alumnos_nom_mod,
        const char *filename){
    ofstream arch(filename,ios::out); 
    
} 

//CURSOS
// cod  nomb    cred    codProf nombProf