

/* 
 * File:   Lista.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:54
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
using namespace std;

// ordenada ASC fecha
class Lista {
private:
    class Nodo *lini;
    class Nodo *lfin;
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    
    void leerPedidos(ifstream &arch); //crear
    void insertarOrden(class Pedido *&dato);
    void imprimeDatos(ofstream &arch);
    void imprimirIterativo(ofstream &arch);
    void actualizaOrden(int prio, int cod); 
    void reordenar(); 
    void insertarInicio(class Pedido *&pedido); 
};

#endif /* LISTA_H */

