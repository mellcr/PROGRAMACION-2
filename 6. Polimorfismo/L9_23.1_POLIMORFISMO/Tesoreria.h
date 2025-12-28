

/* 
 * File:   Tesoreria.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 15:01
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
private:
    class Boleta lboleta[100];
    class Escala lescala[10];
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    //extras
    void cargaescalas();
    void cargaalumnos();
    void actualizaboleta();
    void imprimeboleta();
};

#endif /* TESORERIA_H */

