/* 
 * Proyecto: Biblioteca_Fuentes_2023_1
 * Archivo:   PruebaBiblio.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 3 de abril de 2024, 20:01
 */

#ifndef PRUEBABIBLIO_H
#define PRUEBABIBLIO_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Estructuras.h" 
#include "Overloads.h"
using namespace std;

void probarCurso(ifstream &archEntrada,ofstream &archSalida,
        struct StCurso *cursos,struct StCurso &curso);
void probarAlumno(ifstream &archEntrada,ofstream &archSalida, struct StAlumno 
    *alumnos,struct StAlumno &alumno);
void probarMatricula(ifstream &archEntrada,ofstream &archSalida,
        struct StCurso *cursos,struct StAlumno *alumnos);


#endif /* PRUEBABIBLIO_H */

