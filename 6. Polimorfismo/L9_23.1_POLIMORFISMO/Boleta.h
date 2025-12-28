

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
    void asignaMemoria(char tipo);
    void leeDatos(ifstream &arch);
    bool hayDato();
    int GetEscala();
    void actualizaBoleta(double prec);
    void imprimeBoleta(ofstream &arch);
};

#endif /* BOLETA_H */

