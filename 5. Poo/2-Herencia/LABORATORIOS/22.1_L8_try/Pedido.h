

/* 
 * File:   Pedido.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 10:42
 */

#ifndef PEDIDO_H
#define PEDIDO_H
//#include "Utils.h"
#include "Producto.h"
using namespace std; 

class Pedido:public Producto {
private:
    int codigo; 
    int cantidad; 
    int dni; 
    int fecha; 
    double total; 
    char *obs; 
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetObs(const char* obs);
    void GetObs(char *c) const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    //extras
    void leer(ifstream &arch); 
    void muestra(ofstream &arch); 
    void agregaDescuento(char categoria); 
};

#endif /* PEDIDO_H */

