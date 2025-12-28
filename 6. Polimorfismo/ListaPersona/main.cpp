
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 8 de junio de 2024, 12:55
 */

#include "Utils.h"
#include "Persona.h"
#include "Lista.h"
using namespace std;

/*
 * 378708,SAENZ ARANDA WILMER,23455.6
 */
int main(int argc, char** argv) {
    class Lista lista;
    lista.crear("personal.csv");
    lista.imprimirRec("Reporte-Rec.txt");
    
    return 0;
}

