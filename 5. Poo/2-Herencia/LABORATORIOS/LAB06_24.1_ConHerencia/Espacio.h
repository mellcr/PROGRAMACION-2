

/* 
 * File:   Espacio.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 22:03
 */

#ifndef ESPACIO_H
#define ESPACIO_H
using namespace std;

class Espacio {
private:
    char contenido;
    int posx;
    int posy;
public:
    Espacio();
    Espacio(const Espacio& orig);
    virtual ~Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    //
    void imprimir(ofstream &arch);
};

#endif /* ESPACIO_H */

