/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Espacio.h
 * Author: Josue
 *
 * Created on 28 de mayo de 2024, 11:20 PM
 */

#ifndef ESPACIO_H
#define ESPACIO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Espacio {
public:
    Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
 
private:
    char contenido;
    int posx;
    int posy;
    
};
void operator <<(ofstream &arch,const class Espacio &esp);
#endif /* ESPACIO_H */

