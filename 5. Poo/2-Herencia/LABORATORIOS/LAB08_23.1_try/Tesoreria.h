

/* 
 * File:   Tesoreria.h
 * Author: BlueCod (mell1)
 *
 * Created on 28 de mayo de 2024, 15:24
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria {
private:
    class Presencial lpresencial[50];
    class Semipresencial lsemipresencial[50];
    class Virtual lvirtual[50];
    class Escala lescala[20]; 
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    //funciones 
    void cargaescalas(const char*filename); 
    void cargaalumnos(const char*filename); 
    void actualiza(int );
    void imprime(const char*filename); 
    void imprimeLinea(ofstream &arch);
};

#endif /* TESORERIA_H */

