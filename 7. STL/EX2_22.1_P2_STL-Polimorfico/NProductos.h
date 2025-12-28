

/* 
 * File:   NProductos.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:49
 */

#ifndef NPRODUCTOS_H
#define NPRODUCTOS_H
#include "Producto.h"
using namespace std;

class NProductos {
private:
    class Producto *prod;
    
public:
    NProductos();
    NProductos(const NProductos& orig);
    virtual ~NProductos();
    
    void leeproductos(ifstream &arch);
    void imprimeproductos(ofstream &arch);
    void getPriYCodProd(int &prio, int &cod); 
};

#endif /* NPRODUCTOS_H */

