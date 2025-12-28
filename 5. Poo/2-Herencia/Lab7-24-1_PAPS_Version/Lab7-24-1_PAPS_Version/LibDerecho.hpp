
                    /* CODEANDO CON PAPS */

#ifndef LIBDERECHO_HPP
#define LIBDERECHO_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Libro.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

class LibroDerecho:public Libro{
private:
    char *area;
    char *jurisdiccion;
    int edicion;
public:
    LibroDerecho();
//    LibroDerecho(const LibroDerecho &origen);
//    virtual~LibroDerecho();
    void SetEdicion(int edicion);
    int GetEdicion() const;
    void SetJurisdiccion(const char* jurisdiccion);
    void GetJurisdiccion(char *jurisdiccion) const;
    void SetArea(const char* area);
    void GetArea(char *area) const;
    void leeLibro(ifstream &arch);
    void muestraLibro(ofstream &arch);
};

#endif /* LIBDERECHO_HPP */

                    /* CODEANDO CON PAPS */