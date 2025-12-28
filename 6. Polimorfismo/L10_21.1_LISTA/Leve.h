

/* 
 * File:   Leve.h
 * Author: BlueCod (mell1)
 *
 * Created on 10 de junio de 2024, 22:53
 */

#ifndef LEVE_H
#define LEVE_H
#include "Infraccion.h"


class Leve:public Infraccion {
private:
    double descuento; //porc que se descuenta 
public:
    Leve();
    virtual ~Leve();
    void SetDescuento(double descuento);
    double GetDescuento() const;
};

#endif /* LEVE_H */

