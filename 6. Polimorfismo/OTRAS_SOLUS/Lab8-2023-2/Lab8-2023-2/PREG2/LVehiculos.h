/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   LVehiculos.h
 * Author: Josue
 *
 * Created on 13 de junio de 2024, 10:11 AM
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H
#include <fstream>
using namespace std;
#include "NodoLista.h"
 
class LVehiculos {
public:
    LVehiculos();
    void leeVehiculos(ifstream &arch );
    void insertaNodo(ifstream &arch,char tipo);
    void imprimeVehiculos(ofstream &arch);
    void leePedido(ifstream &arch);
    void colocaPedido(int codCli,char *cadena,int cantidad,double peso);
private:
    class NodoLista *lini;
    class NodoLista *lfin;
};

#endif /* LVEHICULOS_H */

