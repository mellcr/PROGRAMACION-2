/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejemplar.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 09:36 AM
 */

#ifndef EJEMPLAR_H
#define EJEMPLAR_H
#include "Libro.h"
using namespace std;

class Ejemplar { //ES EL NODO 
public:
    Ejemplar();
    Ejemplar(const Ejemplar& orig);
    virtual ~Ejemplar();
    //
    void leeEjemplares(ifstream &arch);
    void asignaMem(char tipo); 
    
    friend class Pila; 
private:
    class Libro *plibro; 
    class Ejemplar *sig; 
    
    
};

#endif /* EJEMPLAR_H */

