/* 
 * Proyecto: Fuentes_Biblioteca_2023_2
 * Archivo:   Sobrecargas.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 4 de abril de 2024, 23:40
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include "Utils.h"
using namespace std;

bool operator >>(ifstream &archLectura, struct Cliente &cliente);
bool operator >>(ifstream &archLectura, struct Producto &produc);
bool operator >>(ifstream &archLectura, struct Pedido &pedido);


#endif /* SOBRECARGAS_H */

