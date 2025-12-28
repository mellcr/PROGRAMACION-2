/* 
 * Proyecto: UsoDeBibEstaticaEnAplicacion
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 4 de abril de 2024, 16:14
 */

#include <iostream>
#include <iomanip> 
using namespace std;
#include "Estructuras.h"
#include "BibliotecaFunciones.h"
#include "AperturaDeArchivos.h"
#include "Funciones.h"
#define NCUR 50
#define NALUM 100
#define NREG 200


int main(int argc, char** argv) {
    struct StCurso cursos[NCUR]{};
    struct StAlumno alumnos[NALUM]{}; 
    
    ifstream archCur, archAlum,archReg,archEsc; 
    ofstream archRep; 
    
    AperturaDeUnArchivoDeTextosParaLeer(archCur,"Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archEsc,"Escalas.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlum,"Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archReg,"Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"reporte.txt");
    
    lecturaCursos(archCur,cursos); 
    lecturaAlum(archAlum,alumnos); 
    procesandoMatricula(archReg,cursos,alumnos); 
    
    calculaTotalesIngresos(archEsc,cursos,alumnos); 
    
    
    imprimeCursosAlumnos(archRep,cursos,alumnos); 
    
    return 0;
}

