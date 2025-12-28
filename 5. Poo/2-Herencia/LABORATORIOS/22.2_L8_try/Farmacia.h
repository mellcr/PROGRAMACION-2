

/* 
 * File:   Farmacia.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 12:50
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "Medico.h"
#include "Sinreceta.h"
#include "Conreceta.h"
using namespace std; 

class Farmacia {
private:
    class Medico lmedico[800]; 
    class Sinreceta lsinreceta[800]; 
    class Conreceta lconreceta[900];
public:
    Farmacia();
    Farmacia(const Farmacia& orig);
    virtual ~Farmacia();
    void cargamedido(); 
    void leerecetas(); 
    void imprimirrecetas(); 
    void asignaMedicamentos(ifstream &arch,
        int fecha,int dniCli,char *nombCli,int codMedico); 
    int buscarEnMedico(int codBus);
    
}; 

#endif /* FARMACIA_H */

