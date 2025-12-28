/* 
 * Proyecto: EX1_23.1_P1_MEM_INCREMENTOS
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 15 de abril de 2024, 16:00
 */
#include "Utils.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
using namespace std;

int main(int argc, char** argv) {
    char ***cursos,***alumnos_nom_mod;
    double *cursos_cred, escalas[5];
    int *alumnos_cod, **alumnos; 
    
    cargarCursosYEscalas(cursos,cursos_cred,escalas,"Cursos.csv","Escalas.csv"); 
    //pruebaDeCargaDeAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"PruebaAlumnos.txt"); 
    
    
    return 0;
}

//CURSOS
//HISTORIA DE NOTAS
//ALUMNOS
// ESCALAS 
