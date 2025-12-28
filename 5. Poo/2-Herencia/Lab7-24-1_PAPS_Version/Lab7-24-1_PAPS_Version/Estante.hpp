
                    /* CODEANDO CON PAPS */

#ifndef ESTANTE_HPP
#define ESTANTE_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Libro.hpp"
#include "LibInf.hpp"
#include "LibDerecho.hpp"
#include "Espacio.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

class Estante{
private:
    char *codigo;
    int anchura;
    int altura;
    Espacio *espacios;
public:
    Estante();
//    Estante(const Estante &origen);
//    virtual~Estante();
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* codigo);
    void GetCodigo( char*codigo) const;
    void leeEstante(ifstream &arch);
    void colocaLibroInf(int anchoUsado, LibroInf &libro);
    void colocaLibroDer(int anchoUsado, LibroDerecho &libro);
    void imprimeLinea(ofstream &arch, int max,char caracter);
    void marcaEstante(ofstream &arch);
    void imprimeEstante(ofstream &arch,int cantLibrosInf);
};

#endif /* ESTANTE_HPP */

                    /* CODEANDO CON PAPS */