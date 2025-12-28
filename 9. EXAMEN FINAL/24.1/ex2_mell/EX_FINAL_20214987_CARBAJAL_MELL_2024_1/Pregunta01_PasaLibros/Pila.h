/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 09:37 AM
 */

#ifndef PILA_H
#define PILA_H
using namespace std; 
class Pila {
public:
    Pila();
    Pila(const Pila& orig);
    virtual ~Pila();
    //
    void apilar(class Ejemplar*&dato);
    void desapilar(); 
    void setNelementos(int nelementos);
    int getNelementos() const; 
    bool pilaVacia(); 
private:
    int nelementos; 
    class Ejemplar *pcima; 
};

#endif /* PILA_H */

