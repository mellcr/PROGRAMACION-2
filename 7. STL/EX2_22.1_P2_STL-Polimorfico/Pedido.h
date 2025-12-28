

/* 
 * File:   Pedido.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:37
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include "Utils.h"
using namespace std;

class Pedido {
private:
    int codigo; //codProd
    int cantidad;
    int dni;
    int fecha;
    double total; //monto del pedido
    int orden; //prioridad de atencion del pedido 1, 0
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetOrden(int orden);
    int GetOrden() const;
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
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* PEDIDO_H */

