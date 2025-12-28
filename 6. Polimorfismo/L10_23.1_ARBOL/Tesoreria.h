

/* 
 * File:   Tesoreria.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 22:53
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Arbol.h"
class Tesoreria {
private:
    class Arbol aboleta;
public:
    Tesoreria();
    void cargaalumnos();
    void actualizaboleta();
    void imprimeboleta();
};

#endif /* TESORERIA_H */

