/* 
 * Proyecto: UsoDeBibEstaticaEnAplicacion
 * Archivo:   Funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 4 de abril de 2024, 16:31
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <iomanip> 
using namespace std;
#include "Estructuras.h"
#include "BibliotecaFunciones.h"

void lecturaAlum(ifstream &archAlum,struct StAlumno *alumnos); 
void lecturaCursos(ifstream &archCur,struct StCurso *cursos); 
void procesandoMatricula(ifstream &archReg,struct StCurso *cursos,
        struct StAlumno *alumnos); 
void imprimeCursosAlumnos(ofstream &archRep,struct StCurso *cursos,
        struct StAlumno *alumnos);

#endif /* FUNCIONES_H */

