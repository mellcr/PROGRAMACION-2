

/* 
 * File:   Grave.h
 * Author: BlueCod (mell1)
 *
 * Created on 10 de junio de 2024, 22:56
 */

#ifndef GRAVE_H
#define GRAVE_H
#include "Infraccion.h"


class Grave:public Infraccion {
private:
    double descuento; //porc
    int puntos; //puntos que pierde el conductor
public:
    Grave();
    virtual ~Grave();
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
};

#endif /* GRAVE_H */

