
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 0:36
 */

#include "Utils.h"
using namespace std;
#include "Tesoreria.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Tesoreria ABoleta;
    
    ABoleta.cargaalumnos();
    ABoleta.imprimeboleta();
    
    return 0;
}

