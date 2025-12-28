/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NodoLista.h
 * Author: Josue
 *
 * Created on 13 de junio de 2024, 10:09 AM
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Vehiculo.h"
#include "NodoLista.h"
#include "LVehiculos.h"
class NodoLista {
public:
    NodoLista();
//    virtual ~NodoLista();
    void asignaMemoria(char tipo);
    friend class LVehiculos;
    void leeDatosCamiones(ifstream &arch);
    void imprimeCamion(ofstream &arch);
private:
    class Vehiculo *unidad;
    //puntero que aplica el polimorfismo
    class NodoLista *sig;
};

#endif /* NODOLISTA_H */

