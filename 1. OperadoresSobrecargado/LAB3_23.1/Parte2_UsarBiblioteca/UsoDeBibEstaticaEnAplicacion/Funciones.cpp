/* 
 * Proyecto: UsoDeBibEstaticaEnAplicacion
 * Archivo:   Funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 4 de abril de 2024, 16:31
 */

#include <iostream>
#include <iomanip>
#include <ios> 
using namespace std;
#include "Estructuras.h"
#include "BibliotecaFunciones.h"

void lecturaCursos(ifstream &archCur,struct StCurso *cursos){
    struct StCurso cur; 
    //inicializamos el primer elemento 
    strcpy(cursos[0].codigoDelCurso,"XXXXXX"); 
    while(true){
        if(archCur>>cur){
            //lo agregamos al arreglo de cursos
            cursos+=cur; 
        }else{
            break;
        }
    }
}    
    

void lecturaAlum(ifstream &archAlum,struct StAlumno *alumnos){
    struct StAlumno alum; 
    //debemos inicializar 
    alumnos[0].semestre = 0; 
    while(true){
        if(archAlum>>alum){ //si esto es TRUE
            alumnos+=alum; //agregamos al arreglo :)) 
        }else{
            break; 
        }
    }
}        

void procesandoMatricula(ifstream &archReg,struct StCurso  *cursos,
        struct StAlumno *alumnos){
    struct StRegistroDeMatricula registro; 
    
    //leemos hasta que se acabe el archivo de reg 
    while(true){
        if(archReg >> registro){
                    //si no encuentra la pos -> no agrega nada 
            cursos *= registro;
            alumnos *= registro;
        }else{
            break; 
        }        
        
    }
    
}

void calculaTotalesIngresos(ifstream &archEsc,struct StCurso *cursos,
        struct StAlumno *alumnos){
    char car; 
    int numEscala; 
    double monto; 
    
    while(true){
        archEsc >> car; 
        if(archEsc.eof()) break; 
        archEsc >> numEscala>>monto; 
        archEsc.get(); //lee el cambio de linea 
        
        
        
        
        
        
    }
    
    
    
}










void imprimeCursosAlumnos(ofstream &archRep,struct StCurso *cursos,
        struct StAlumno *alumnos){
    archRep << " CURSOS "<<endl; 
    //archRep<<cursos[0]; 
        for(int i=0; strcmp(cursos[i].codigoDelCurso, "XXXXXX") != 0; i++){
            archRep << cursos[i];
            archRep << endl; 
        }
            
    archRep << right << setw(62) << "REPORTE DE ALUMNOS" << left << endl << endl;
//    for(int i=0; alumnos[i].semestre != 0; i++){
//        archRep << alumnos[i];
//        //archRep<< endl;
//    }
    //archRep << alumnos[0]; 
}