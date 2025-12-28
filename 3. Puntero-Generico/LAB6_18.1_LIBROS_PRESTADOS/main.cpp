/* 
 * Proyecto: LAB6_18.1_LIBROS_PRESTADOS
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 21 de abril de 2024, 18:02
 */

#include "Utils.h"
#include "Bib_Func_Preg1.h"
using namespace std;

//USUARIOS: codUsu,nombUsu
//PRESTAMOS: libros q tiene q devolver el usu (estan fuera de la biblioteca) 
//codUsu, codLib, fechaDev
int main(int argc, char** argv) {
    void *usuarios;
    //PREGUNTA1
    leerUsuarios(usuarios);
    //imprimirUsuarios(usuarios);
    
    leerPRestamos(usuarios); 
    imprimirPrestamso(usuarios);
    return 0;
}

//cap x cada cliente