

/* 
 * File:   Item.h
 * Author: BlueCod (mell1)
 *
 * Created on 25 de mayo de 2024, 16:08
 */

#ifndef ITEM_H
#define ITEM_H
#include "Utils.h"
using namespace std;

class Item {
private:
    char *nombre;
    char *descripcion;
    //Hero arrheroes[20];
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char *) const;
    void SetNombre(const char* nombre);
    void GetNombre(char *) const;
    //int GetHeroeHp(int indice);
    void mostrar();
    
protected: 
    int protegida; 
};

#endif /* ITEM_H */

