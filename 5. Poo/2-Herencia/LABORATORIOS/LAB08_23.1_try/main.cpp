
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 25 de mayo de 2024, 20:28
 */

#include "Utils.h"
#include "Tesoreria.h"
using namespace std;


int main(int argc, char** argv) {
    Tesoreria caja; 
    
    caja.cargaescalas("escalas.csv");
    caja.cargaalumnos("Alumnos.csv"); 
    caja.actualiza(20); 
    caja.imprime("Reporte.txt"); 
    
    
    return 0;
}

