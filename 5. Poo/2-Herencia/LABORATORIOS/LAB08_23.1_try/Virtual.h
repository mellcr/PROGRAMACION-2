

/* 
 * File:   Virtual.h
 * Author: BlueCod (mell1)
 *
 * Created on 28 de mayo de 2024, 15:15
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"

class Virtual: public Alumno{
private:
    char *licencia;  
    double total;    //monto de la licencia -> 100.00
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void  GetLicencia(char *) const;
    void leerDatos(ifstream& arch); 
    void actualiza(double monto); 
    void imprime(ofstream &arch);
};

#endif /* VIRTUAL_H */

