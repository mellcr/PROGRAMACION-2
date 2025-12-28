

/* 
 * File:   Conreceta.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 12:44
 */

#ifndef CONRECETA_H
#define CONRECETA_H
#include "Medicamento.h"
using namespace std;

class Conreceta:public Medicamento {
private:
    int codmed; 
    char *especialidad; 
public:
    Conreceta();
    Conreceta(const Conreceta& orig);
    virtual ~Conreceta();
    void SetEspecialidad(const char* especialidad);
    void GetEspecialidad(char *c) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    //extra
    void leer(int codMedico, int codMedicam,int cant,int fecha,
            char *buffEsp); 
    void imprime(ofstream &arch);
};

#endif /* CONRECETA_H */

