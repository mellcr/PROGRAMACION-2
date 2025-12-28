

/* 
 * File:   Semipresencial.h
 * Author: BlueCod (mell1)
 *
 * Created on 28 de mayo de 2024, 15:12
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"
using namespace std; 

class Semipresencial :public Alumno {
private:
    double descuento; //almacena porcentaje  
    double total;     //monto del descuento 
    
public:
    Semipresencial();
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leerDatos(ifstream &); 
    //extras
    void actualiza(double monto);
    void imprime(ofstream &arch);
};

#endif /* SEMIPRESENCIAL_H */

