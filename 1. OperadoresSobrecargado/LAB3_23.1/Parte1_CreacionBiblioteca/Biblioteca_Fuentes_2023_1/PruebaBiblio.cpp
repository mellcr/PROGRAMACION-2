/* 
 * Proyecto: Biblioteca_Fuentes_2023_1
 * Archivo:   PruebaBiblio.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 3 de abril de 2024, 20:01
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Estructuras.h" 
#include "Overloads.h"
using namespace std;


//prueba la lect del curso y su agregacion al arreglo de cursos
void probarCurso(ifstream &archEntrada,ofstream &archSalida,
        struct StCurso *cursos,struct StCurso &curso){
    archSalida << "Prueba #1: Lectura de curso "<<endl<<endl; 
    
    //leemos solo una linea
    archEntrada >> curso; 
    archSalida <<curso;   //la imprimimos 
    
    //inicializo 
    strcpy(cursos[0].codigoDelCurso,"XXXXXX");
    cursos += curso; 
    archSalida << "Prueba #2: Agregacion de curso a arreglo de cursos"<<endl; 
    archSalida << cursos[0]; //imprimo el que agregue 
}

//prueba la lectura de 1 alumno y su agregacion en el arreglo de alumnos
void probarAlumno(ifstream &archEntrada,ofstream &archSalida, struct StAlumno 
    *alumnos,struct StAlumno &alumno){
    
    archSalida << "Prueba #3: Lectura de un alumno"<<endl; 
    archEntrada >> alumno;
    archSalida << alumno; 
    
    archSalida << "Prueba #4: Agregacion de alumno al arrAlum"<<endl;
    //inicializamos 
    alumnos[0].semestre = 0; 
    alumnos+= alumno;
    archSalida << alumnos[0]; 
    
}

void probarMatricula(ifstream &archEntrada,ofstream &archSalida,
        struct StCurso *cursos,struct StAlumno *alumnos){
    struct StRegistroDeMatricula matric;
    
    archSalida<<endl<<endl <<"Prueba #5: Lectura de matriculados"<<endl;
    archEntrada>>matric; // currso, semestre, codAlum
    //imprimimos
    archSalida<<"Curso: "<<matric.codigoDelCurso<<endl;
    archSalida<<"Semestre: "<<matric.semestreDelAlumno<<endl;
    archSalida<<"Alumno: "<<matric.codigodelAlumno<<endl;
    

    //le pongo el cod y semestre del alumno q lei (el primero) 
    //para que se noten los cambios
    matric.codigodelAlumno = 1260;
    matric.semestreDelAlumno = 20211;
//    //HAY ERROR AQUI
    cursos*=matric;
    alumnos*=matric; 
    
//    
//    
    archSalida <<endl<< "Prueba #6: Agregar alumno al curso q se matriculo"<<endl; 
    archSalida<<alumnos[0];
    archSalida <<endl<< "Prueba 7: Agregar un curso al ALUMNO q se matriculo"
            <<endl;
    archSalida << cursos[0];
}











