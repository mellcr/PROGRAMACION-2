

/* 
 * File:   Semipresencial.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 14:42
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial:public Alumno {
private:
    double descuento; //porc
    double total; //monto del desc
public:
    Semipresencial();
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    //
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* SEMIPRESENCIAL_H */

