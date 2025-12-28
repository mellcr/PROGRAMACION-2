/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 28 de mayo de 2024, 11:12 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Biblioteca.h"
#include "Espacio.h"
#include "Libro.h"
#include "Estante.h"
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archLib("libros.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR AL ABRIR "<<"libros.csv"<<endl;
    }
    
    ifstream archEst("estantes.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR AL ABRIR "<<"estantes.csv"<<endl;
    }
    class Libro lib;
    archLib>>lib;
    class Estante est;
    archEst>>est;
    est+=lib;
    ofstream archRep("RepPrueba.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR AL ABRIR "<<"RepPrueba.txt"<<endl;
    }
    archRep<<est;
    archRep<<lib;
    class Espacio esp;
    archRep<<esp;
    return 0;
}

