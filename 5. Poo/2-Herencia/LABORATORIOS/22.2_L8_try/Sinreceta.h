

/* 
 * File:   Sinreceta.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 12:47
 */

#ifndef SINRECETA_H
#define SINRECETA_H
#include "Medicamento.h"
using namespace std;

class Sinreceta:public Medicamento {
private:
    int dni; 
    char *nombre; 
public:
    Sinreceta();
    Sinreceta(const Sinreceta& orig);
    virtual ~Sinreceta();
    void SetNombre(const char* nombre);
    void GetNombre(char *c) const;
    void SetDni(int dni);
    int GetDni() const;
    void leer(int dniCli,char *nombCli,int codMedicam,int cant,
                       int fecha);
    void imprime(ofstream &arch);
};

#endif /* SINRECETA_H */

