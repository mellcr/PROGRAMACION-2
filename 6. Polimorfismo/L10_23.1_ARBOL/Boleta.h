

/* 
 * File:   Boleta.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 14:48
 */

#ifndef BOLETA_H
#define BOLETA_H
#include "Alumno.h"
using namespace std;

class Boleta {
private:
    class Alumno *pboleta;
public:
    Boleta();
    virtual ~Boleta();
    //extras
    void SetNull();
    void asignaMemoria(char tipo);
    void leeDatos(ifstream &arch);
    bool operator > (const class Boleta &); //arbol->dboleta > dato
    //void operator =(const class Boleta&); //arbol->dboleta = dato; //son punteros 
    void imprimeDatos(ofstream &arch) const;
    void imprimeCod();
};
//arch<<raiz->dboleta;
void operator <<(ofstream &arch,const class Boleta &);

#endif /* BOLETA_H */

