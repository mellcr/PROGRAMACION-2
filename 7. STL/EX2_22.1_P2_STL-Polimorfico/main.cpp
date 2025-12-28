
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:34
 */

#include "Utils.h"
using namespace std;
#include "Programa.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Programa pro;
    
    pro.carga();
    pro.actualiza();
    pro.muestraproductos();
    
    return 0;
}

