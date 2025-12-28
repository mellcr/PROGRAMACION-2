

/* 
 * File:   Consumible.h
 * Author: BlueCod (mell1)
 *
 * Created on 25 de mayo de 2024, 16:50
 */

#ifndef CONSUMIBLE_H
#define CONSUMIBLE_H
#include "Item.h"
//#include "Pokeball.h" -> consumible no deberia tener ratio 
class Consumible:public Item{
private:
    int incremento;
public:
    Consumible();
    Consumible(const Consumible& orig);
    virtual ~Consumible();
    void setIncremento(int incremento);
    int getIncremento() const;
};

#endif /* CONSUMIBLE_H */

