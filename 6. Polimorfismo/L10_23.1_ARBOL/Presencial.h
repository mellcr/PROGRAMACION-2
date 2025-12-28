

/* 
 * File:   Presencial.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 14:40
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"
using namespace std;

class Presencial:public Alumno {
private:
    double recargo; //porc
    double total; //monto 
public:
    Presencial();
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    //extras
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* PRESENCIAL_H */

