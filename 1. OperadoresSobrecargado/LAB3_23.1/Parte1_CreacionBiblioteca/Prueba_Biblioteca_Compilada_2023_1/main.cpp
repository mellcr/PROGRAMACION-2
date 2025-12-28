/* 
 * Proyecto: Prueba_Biblioteca_Compilada_2023_1
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 4 de abril de 2024, 15:58
 */

#include <iostream>
#include <iomanip> 
using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "BibliotecaFunciones.h"
#include "PruebaBiblio.h"

int main(int argc, char** argv) {
    ifstream archCursos,archAlumnos,archMatricula;
    ofstream archRep;  
    //2.DECLARACION DE ESTRUCTURAS 
    struct StAlumno alumno,alumnos[100]{};
    struct StCurso curso,cursos[10]{};
    //struct StRegistroDeMatricula reg; 
    //3.APERTURA DE ARCHIVOS
    AperturaDeUnArchivoDeTextosParaLeer(archCursos,"Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos,"Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula,"Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"reporte.txt");
    
    
    //4. REALIZAR PRUEBAS 
    probarCurso(archCursos,archRep,cursos,curso);
    probarAlumno(archAlumnos,archRep,alumnos,alumno);
    probarMatricula(archMatricula,archRep,cursos,alumnos);
    return 0;
}

