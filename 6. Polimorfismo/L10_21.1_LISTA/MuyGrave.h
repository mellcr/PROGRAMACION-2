

/* 
 * File:   MuyGrave.h
 * Author: BlueCod (mell1)
 *
 * Created on 10 de junio de 2024, 22:58
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H
#include "Infraccion.h"


class MuyGrave: public Infraccion {
private:
    int puntos;
    int meses; //cantidad de meses de suspension 
public:
    MuyGrave();
    virtual ~MuyGrave();
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
};

#endif /* MUYGRAVE_H */

