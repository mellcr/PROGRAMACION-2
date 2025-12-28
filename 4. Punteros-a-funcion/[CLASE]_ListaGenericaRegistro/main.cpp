/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 30 de abril de 2024, 15:16
 */

#include "Utils.h"
#include "BibliotecaListaGenerica.h"
#include "ListaRegistrosVoid.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *lista_registros; 
    crear_lista("personal.csv",lista_registros, leer_registro, cmp_registro_str);
    //imprime_lista("Reporte-ListaInsertadoAlfinal.txt",lista_registros, imprimeRegistro); // lista + funcImprimeUNreg 
    imprime_lista("Reporte-InsertarAlinicio.txt",lista_registros, imprimeRegistro); // lista + funcImprimeUNreg 
    
    eliminar_lista(lista_registros, elimina_registro);
     
    
    
    return 0;
}

