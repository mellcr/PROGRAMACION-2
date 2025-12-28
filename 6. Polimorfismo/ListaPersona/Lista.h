

/* 
 * File:   Lista.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de junio de 2024, 13:06
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
using namespace std;

class Lista {
private:
    class Nodo *lista; //puntero lista de tipo class Nodo 
    void imprimeRecursivo(ofstream &arch,class Nodo *);
public:
    Lista();
    //Lista(const Lista& orig); -> no puede existir un método dndce se copie esta estructura 
    virtual ~Lista();
    void elimina();
    void crear(const char *filename);
    void insertar(const class Persona &dato);
    void imprimirIterativo(const char *filename);
    void imprimirRec(const char *filename);
};



#endif /* LISTA_H */

