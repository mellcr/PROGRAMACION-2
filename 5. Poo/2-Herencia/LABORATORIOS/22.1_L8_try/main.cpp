
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 10:27
 */

#include "Utils.h"
#include "Tienda.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Tienda tienda; 

    tienda.carga(); 
    tienda.actualiza(20); 
    tienda.muestra(); 
    
    return 0;
}

