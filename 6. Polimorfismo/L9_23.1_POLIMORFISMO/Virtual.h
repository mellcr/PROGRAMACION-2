

/* 
 * File:   Virtual.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 14:43
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"

class Virtual:public Alumno {
private:
    char *licencia;
    double total;
public: 
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void GetLicencia(char*c) const;
    //
    void lee(ifstream &arch);
    void actualizatotal(double prec);
    void imprime(ofstream &arch);
};

#endif /* VIRTUAL_H */

