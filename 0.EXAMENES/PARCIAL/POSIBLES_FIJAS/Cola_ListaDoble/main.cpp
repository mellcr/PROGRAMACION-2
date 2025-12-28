
/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 12 de mayo de 2024, 7:55
 */

#include  "Utils.h"
#include "colaGenerica.h"
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    void *colaErasmo;
    creaColitaDobleEnlazada(colaErasmo,"DatosPrioridad.txt");
    imprimeCola(colaErasmo,"PruebaPrioridad.txt");
    return 0;
}

