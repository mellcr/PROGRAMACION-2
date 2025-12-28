

/* 
 * File:   Bus.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 10:38 p. m.
 */

#ifndef BUS_H
#define BUS_H
#include "Utils.h"
using namespace std;

class Bus {
private:
    string placa;
    string nombre_chofer;
    int n_pasajeros;
    //vector
    vector <string> rutas;
    int n_rutas;
public:
    Bus();
    Bus(const Bus& orig);
    virtual ~Bus();
    void SetN_rutas(int n_rutas);
    int GetN_rutas() const;
    void SetN_pasajeros(int n_pasajeros);
    int GetN_pasajeros() const;
    void SetNombre_chofer(string nombre_chofer);
    string GetNombre_chofer() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    //
    void leer(ifstream &arch);
    void mostrarbus() const;
    void imprime_rutas() const ;
    string getCiudadActual(int pos) const;
};

#endif /* BUS_H */

