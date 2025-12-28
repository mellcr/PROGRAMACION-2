

/* 
 * File:   Ciudad.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 10:42 p. m.
 */

#ifndef CIUDAD_H
#define CIUDAD_H
#include "Utils.h"
using namespace std;

class Ciudad {
private:
    string nombre;
    double cord_x;
    double cord_y;
public:
    Ciudad();
    Ciudad(const Ciudad& orig);
    virtual ~Ciudad();
    void SetCord_y(double cord_y);
    double GetCord_y() const;
    void SetCord_x(double cord_x);
    double GetCord_x() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    //
    void leer(ifstream &arch);
    void mostra(ofstream &arch) const;
    void mostra() const;
};

#endif /* CIUDAD_H */

