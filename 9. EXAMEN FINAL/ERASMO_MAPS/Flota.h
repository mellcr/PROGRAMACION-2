

/* 
 * File:   Flota.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 10:33 p. m.
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "Utils.h"
#include "Bus.h"
#include "Ciudad.h"
using namespace std;

class Flota {
private:
    vector <Bus> buses;
    vector <Ciudad> ciudades;
    map <string, vector<Ciudad>> rutas;
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    
    void cargar_buses();
    void cargar_ciudades();
    void mostrar_buses2();
    void mostrar_buses() const;
    void armar_rutas();
    void imprimir_rutas(const char *filename);
    void mostrar_ciudades() const ;
    int buscarCiudad(string ciudadActual) const ;
};

#endif /* FLOTA_H */

