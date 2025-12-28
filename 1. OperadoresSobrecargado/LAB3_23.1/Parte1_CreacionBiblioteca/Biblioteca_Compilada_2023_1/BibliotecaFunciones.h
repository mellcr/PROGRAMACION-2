/* 
 * Proyecto: Biblioteca_Fuentes_2023_1
 * Archivo:   Overloads.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 3 de abril de 2024, 15:25
 */

#ifndef OVERLOADS_H
#define OVERLOADS_H
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cstring> 
using namespace std;
#include "Estructuras.h"

bool operator >> (ifstream &in, struct StCurso &curso);
bool operator >> (ifstream &in, struct StAlumno &alum);
bool operator >> (ifstream &in, struct StRegistroDeMatricula &matr); 
void operator +=(struct StAlumno *arrAlum, struct StAlumno &alum);
void operator +=(struct StCurso *arrCur, struct StCurso &cur);

int buscarEnCurso(char *codBuscado,struct StCurso *arrCur);
void operator *=(struct StCurso *arrCur, struct StRegistroDeMatricula &regisMatric);
int buscarEnAlum(int codAlumBus,struct StAlumno *arrAlum); 
void operator *=(struct StAlumno *arrAlum, struct StRegistroDeMatricula &reg); 

void operator <<(ofstream &arcRep, struct StCurso &curso);
void operator <<(ofstream &arcRep, struct StAlumno &alumno);


#endif /* OVERLOADS_H */

