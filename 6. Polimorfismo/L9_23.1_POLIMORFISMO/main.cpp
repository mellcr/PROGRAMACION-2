
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 0:30
 */

#include "Utils.h"
#include "Tesoreria.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tesoreria OTeso;
    
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    OTeso.actualizaboleta();
    OTeso.imprimeboleta();
    
    return 0;
}

