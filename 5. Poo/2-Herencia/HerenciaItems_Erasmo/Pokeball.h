

/* 
 * File:   Pokeball.h
 * Author: BlueCod (mell1)
 *
 * Created on 25 de mayo de 2024, 16:22
 */

#ifndef POKEBALL_H
#define POKEBALL_H
#include "Item.h"
// LA CLASE POKEBALL VA A HEREDAR DE ITEM 
class Pokeball:public Item { // hereda las propiedades publicas de item
private:
    double ratio; //ratio de atrapado de las pokeboals 
public:
    Pokeball();
    Pokeball(const Pokeball& orig);
    virtual ~Pokeball();
    void setRatio(double ratio);
    double getRatio() const;
    void mostrar();
};

#endif /* POKEBALL_H */

