/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: Josue
 *
 * Created on 13 de junio de 2024, 10:12 AM
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "LVehiculos.h"
class Flota {
public:
    void cargaflota();
    void muestracarga();
private:
    class LVehiculos lista;
};

#endif /* FLOTA_H */

