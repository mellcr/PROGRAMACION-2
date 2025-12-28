

/* 
 * File:   Presencial.h
 * Author: BlueCod (mell1)
 *
 * Created on 25 de mayo de 2024, 20:59
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"

class Presencial:public Alumno {
private:
    double recargo;  //porcentaje 
    double total;    //monto del recargo 
public:
    Presencial();
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leerDatos(ifstream& arch);
    void actualiza(double monto); 
    void imprime(ofstream &arch); 
};

#endif /* PRESENCIAL_H */

