/* 
 * Proyecto: Biblioteca_Fuentes_2023_1
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 3 de abril de 2024, 15:22
 */

#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cstring> 
using namespace std;
#include "AperturaDeArchivos.h"
#include "Overloads.h"
#include "Estructuras.h"
#include "PruebaBiblio.h"

int main(int argc, char** argv) {
    //1.DECLARACION DE ARCHICOS
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

