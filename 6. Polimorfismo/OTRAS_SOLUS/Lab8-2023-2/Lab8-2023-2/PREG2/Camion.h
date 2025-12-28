/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Camion.h
 * Author: Josue
 *
 * Created on 13 de junio de 2024, 10:06 AM
 */

#ifndef CAMION_H
#define CAMION_H
#include "Vehiculo.h"
class Camion:public Vehiculo {
public:
    Camion();
 
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream &arch );
    void imprime(ofstream &arch); 
private:
    int ejes;
    int llantas;
};

#endif /* CAMION_H */

