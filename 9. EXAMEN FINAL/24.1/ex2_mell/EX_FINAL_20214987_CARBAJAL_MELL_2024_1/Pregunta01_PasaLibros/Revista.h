/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 09:35 AM
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"
using namespace std; 

class Revista:public Libro {
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    //
    void lee(ifstream &arch);
private:
    int ISSN; 
    int anho; 
    int numero; 
    
};

#endif /* REVISTA_H */

