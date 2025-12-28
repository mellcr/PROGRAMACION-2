
                    /* CODEANDO CON PAPS */

#ifndef ESPACIO_HPP
#define ESPACIO_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>

                    /* CODEANDO CON PAPS */

using namespace std;

class Espacio{
private:
    char contenido;
    int posx;
    int posy;
public:
    Espacio();
//    Espacio(const Espacio &origen);
//    virtual~Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    void muestraEspacio(ofstream &arch);
};

#endif /* ESPACIO_HPP */

                    /* CODEANDO CON PAPS */