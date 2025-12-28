
/* 
 * File:   Tesoreria.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 22:53
 */
#include "Utils.h"
#include "Tesoreria.h"
using namespace std;

Tesoreria::Tesoreria() {
}

void Tesoreria::cargaalumnos(){
    aboleta.crear("alumnos.csv");
}

void Tesoreria::actualizaboleta(){
    
}

void Tesoreria::imprimeboleta(){
    aboleta.imprimirEnOrden("Reporte.txt");
}