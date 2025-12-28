/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 09:40 AM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include "Pila.h"
using namespace std; 

class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    //
    void carga(); 
    void asignarMemoria(char tipo,class Ejemplar *&dato);
    void pasa(); 
    void muestra(); 
private:
    class Pila porigen; 
    class Pila pdestino; 
};

#endif /* PROCESA_H */

