
                    /* CODEANDO CON PAPS */

#ifndef LIBINGINF_HPP
#define LIBINGINF_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include"Libro.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

class LibroInf:public Libro{
private:
    char *tema;
    char *lenguaje;
    int dificultad;
public:
    LibroInf();
//    LibroInf(const LibroInf &origen);
//    virtual~LibroInf();
    void SetDificultad(int dificultad);
    int GetDificultad() const;
    void SetLenguaje(const char* lenguaje);
    void GetLenguaje(char *lenguaje) const;
    void SetTema(const char* tema);
    void GetTema(char *tema) const;
    void leeLibro(ifstream &arch);
    void muestraLibro(ofstream &arch);
};

#endif /* LIBINGINF_HPP */

                    /* CODEANDO CON PAPS */