
                    /* CODEANDO CON PAPS */

#ifndef LIBRO_HPP
#define LIBRO_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>

                    /* CODEANDO CON PAPS */

using namespace std;

class Libro{
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro();
//    Libro(const Libro &origen);
//    virtual~Libro();
    void SetColocado(bool colocado);
    bool GetColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*nombre) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*codigo) const;
    void leeLibro(ifstream &arch);
    void muestraLibro(ofstream &arch);
};

#endif /* LIBRO_HPP */

                    /* CODEANDO CON PAPS */