/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 09:33 AM
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"
using namespace std; 

class Novela:public Libro {
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetEditorial(const char* editorial);
    void GetEditorial(char*c) const;
    void SetAutor(const char* autor);
    void GetAutor(char*c) const;
    //
    void lee(ifstream &arch);
    
private:
    char *autor; 
    char *editorial; 
    
};

#endif /* NOVELA_H */

