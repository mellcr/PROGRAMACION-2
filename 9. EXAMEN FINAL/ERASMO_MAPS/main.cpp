
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 10:32 p. m.
 */

#include "Utils.h"
#include "Flota.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Flota flota;

    flota.cargar_buses();
//    flota.mostrar_buses();
    flota.mostrar_buses2();
    flota.cargar_ciudades();
    flota.mostrar_ciudades();
    flota.armar_rutas();
    flota.imprimir_rutas("reporte.txt");
    
    return 0;
}

