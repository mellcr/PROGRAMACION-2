

/* 
 * File:   Programa.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:55
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <vector>
using namespace std;
#include "Lista.h"
#include "NProductos.h"

class Programa {
private:
    class Lista lpedidos; 
    vector<class NProductos>vproductos;
public:
    Programa();
    Programa(const Programa& orig);
    virtual ~Programa();
    
    void carga();
    void cargaLista();
    void cargaproductos();
    void muestraproductos();
    void actualiza(); 
};

#endif /* PROGRAMA_H */

